#include "networkplot.h"
#include "ui_networkplot.h"

NetworkPlot::NetworkPlot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NetworkPlot)
{
    ui->setupUi(this);


    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); // point shape
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->xAxis->setLabel("X");
    ui->customPlot->yAxis->setLabel("Y");
    ui->customPlot->xAxis->setRange(-6000,100);
    ui->customPlot->yAxis->setRange(-6000,8000);

    /* move-zoom-chose line plot chart */
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    hide_minorPlot();// add new minor Plot

}

NetworkPlot::~NetworkPlot()
{
    delete ui;
}


void NetworkPlot::on_plotButton_clicked()
{
    QVector<double> x = {1,2,3,4,5},y={4,6,3,2,4};// point

    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
    ui->customPlot->update();


    ui->minorPlot->graph(0)->setData(y,x);
    ui->minorPlot->rescaleAxes();
    ui->minorPlot->replot();
    ui->minorPlot->update();
}

void NetworkPlot::on_pushButton_clicked()
{
    ui->minorPlot->graph(0)->data()->clear();
    ui->minorPlot->replot();
    ui->minorPlot->update();

}
void NetworkPlot::hide_minorPlot(){
    //file.pro add MAKE PATH
    //UI chose WIDGET -> clkRIGHT -> Promote to... -> write QWidget,QCustomePlot,qcustomplot.h ->add + tick + promote
    ui->minorPlot->addGraph();
    ui->minorPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle); // point shape
    ui->minorPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->minorPlot->xAxis->setLabel("X");
    ui->minorPlot->yAxis->setLabel("Y");
    ui->minorPlot->xAxis->setRange(-6000,100);
    ui->minorPlot->yAxis->setRange(-6000,8000);

    /* move-zoom-chose line plot chart */
    ui->minorPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);


    /*QVector<double> xm = {1,2,3,4,5},ym={4,6,3,2,4};// point

    ui->minorPlot->graph(0)->setData(ym,xm);
    ui->minorPlot->rescaleAxes();
    ui->minorPlot->replot();
    ui->minorPlot->update();*/
}
