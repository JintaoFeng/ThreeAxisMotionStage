#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QListWidgetItem>
#include "axis.h"
#include <QTableWidget>
#include <QList>
#include "table.h"
#include "ACSC.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class axis;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void ReadXML();
    void WriteXML();
    static HANDLE hComm;


public slots:
    void ShowTime();
    void CommandHandler(int value);
    HANDLE GetHandle()
    {
        return hComm;
    }
private slots:

    void on_tabWidget_customContextMenuRequested(const QPoint &pos);

    void AddTab();
    void DeleteTab();

    void AddPoint();
    void DeletePoint();

    void on_connectBtn_clicked();

    void on_enableAllBtn_clicked();

    void on_killStopBtn_clicked();

    void on_setBtn_clicked();

    void on_moveBtn_clicked();

    void on_saveBtn_clicked();

    void on_loadBtn_clicked();

    void on_tabWidget_tabBarDoubleClicked(int index);


    void on_connectBox_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    axis* axi1;
    axis* axi2;
    axis* axi3;

    int retValue;

    int axisStatus1;
    int axisStatus2;
    int axisStatus3;
    int motorStatus1;
    int motorStatus2;
    int motorStatus3;
    QThread *homeThread1;
    QThread *homeThread2;
    QThread *homeThread3;

    QList<table*> tabWid;

    char* errorStr;
    int errorCount;
    int* errorSize;
    QSettings *setting;
    ACSC_CONNECTION_INFO connectInfo;
    int axi[4];

signals:
    void updateStart();
    void updateTerm();
    void setPoint(QVector<double> point);
    void move(QVector<double> pos);
};
#endif // MAINWINDOW_H
