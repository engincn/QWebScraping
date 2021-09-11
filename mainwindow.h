#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "html.h"
#include "file.h"
#include "parser.h"
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QLabel;
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void labelUpdate();
    void changeColor( int mNumber, QString change );
    void write_M_change_Rate(int ln, parser &prs, int changeLine, QLabel *label);

private:
    Ui::MainWindow *ui;
    html *htmll;
    QTimer *timer;
    int countTimer;

private slots:
    void printText();
    void on_updateButton_clicked();
    void on_autoUpdate_stateChanged();
    void update_slots();
};
#endif // MAINWINDOW_H
