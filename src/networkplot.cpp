#include "networkplot.h"
#include "ui_networkplot.h"

NetworkPlot::NetworkPlot(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NetworkPlot)
{
    ui->setupUi(this);


    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->customPlot->graph(0)->setLineStyle(QCPGraph::lsLine);
    ui->customPlot->xAxis->setLabel("X");
    ui->customPlot->yAxis->setLabel("Y");
    ui->customPlot->xAxis->setRange(-6000,100);
    ui->customPlot->yAxis->setRange(-6000,8000);

    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);

    QVector<double> x = {1,2,3,4,5},y={4,6,8,2,5};

    ui->customPlot->graph(0)->setData(x,y);
    ui->customPlot->rescaleAxes();
    ui->customPlot->replot();
    ui->customPlot->update();

    //ui->plotTypeComboBox->setCurrentIndex(4);
    //ui->lineStyleComboBox->setCurrentIndex(1);

}

NetworkPlot::~NetworkPlot()
{
    delete ui;
}

