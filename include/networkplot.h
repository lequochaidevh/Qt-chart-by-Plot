#ifndef NETWORKPLOT_H
#define NETWORKPLOT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class NetworkPlot; }
QT_END_NAMESPACE

class NetworkPlot : public QMainWindow
{
    Q_OBJECT

public:
    NetworkPlot(QWidget *parent = nullptr);
    ~NetworkPlot();

private slots:
    void on_plotButton_clicked();

    void on_clearButton_clicked();

    void hide_minorPlot();

    void on_lineStylecomboBox_currentIndexChanged(int index);

    void on_SCattercomboBox_currentIndexChanged(int index);

private:
    Ui::NetworkPlot *ui;
};
#endif // NETWORKPLOT_H
