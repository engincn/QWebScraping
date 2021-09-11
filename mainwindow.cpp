#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    htmll = new html();
    QObject::connect(htmll, &html::finishSignal, this, &MainWindow::printText);
    htmll->getURL("https://www.website.com");

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::update_slots);

    ui->statusbar->showMessage("Mode: Manuel update");
}

MainWindow::~MainWindow()
{
    delete  ui;
    delete  htmll;
    delete  timer;
}

void MainWindow::printText(void)
{
    file xml;
    xml.writeFile(htmll->getHtml());
    labelUpdate();
}


void MainWindow::on_updateButton_clicked()
{
    labelUpdate();
}

void MainWindow::labelUpdate()
{
    parser xmlFile("out.xml");

    //  Money 1
    ui->m1Name->setText("ABD Doları");
    ui->m1Change->setText(QString::fromStdString(xmlFile.readPart(733,69,2)));
    ui->m1Buy->setText(QString::fromStdString(xmlFile.readPart(734,48,6)));
    ui->m1Sale->setText(QString::fromStdString(xmlFile.readPart(735,48,6)));
    write_M_change_Rate(736, xmlFile, 733, ui->m1cRate);
    changeColor( 1, QString::fromStdString(xmlFile.readPart(733,69,2)) );

    // Money 2
    ui->m2Name->setText("Euro");
    ui->m2Change->setText(QString::fromStdString(xmlFile.readPart(741,69,2)));
    ui->m2Buy->setText(QString::fromStdString(xmlFile.readPart(742,48,6)));
    ui->m2Sale->setText(QString::fromStdString(xmlFile.readPart(743,48,6)));
    write_M_change_Rate(744, xmlFile, 741, ui->m2cRate);
    changeColor( 2, QString::fromStdString(xmlFile.readPart(741,69,2)) );

    // Money 3
    ui->m3Name->setText("Ingiliz Sterlini");
    ui->m3Change->setText(QString::fromStdString(xmlFile.readPart(749,69,2)));
    ui->m3Buy->setText(QString::fromStdString(xmlFile.readPart(750,48,6)));
    ui->m3Sale->setText(QString::fromStdString(xmlFile.readPart(751,48,6)));
    write_M_change_Rate(752, xmlFile, 749, ui->m3cRate);
    changeColor( 3, QString::fromStdString(xmlFile.readPart(749,69,2)) );

    // Money 4
    ui->m4Name->setText("Isvicre Frangı");
    ui->m4Change->setText(QString::fromStdString(xmlFile.readPart(757,69,2)));
    ui->m4Buy->setText(QString::fromStdString(xmlFile.readPart(758,48,6)));
    ui->m4Sale->setText(QString::fromStdString(xmlFile.readPart(759,48,6)));
    write_M_change_Rate(760, xmlFile, 757, ui->m4cRate);
    changeColor( 4, QString::fromStdString(xmlFile.readPart(757,69,2)) );

    // Money 5
    ui->m5Name->setText("Japon Yeni");
    ui->m5Change->setText(QString::fromStdString(xmlFile.readPart(765,69,2)));
    ui->m5Buy->setText(QString::fromStdString(xmlFile.readPart(766,48,6)));
    ui->m5Sale->setText(QString::fromStdString(xmlFile.readPart(767,48,6)));
    write_M_change_Rate(768, xmlFile, 765, ui->m5cRate);
    changeColor( 5, QString::fromStdString(xmlFile.readPart(765,69,2)) );

    // Money 6
    ui->m6Name->setText("Suudi Arabistan Riyali");
    ui->m6Change->setText(QString::fromStdString(xmlFile.readPart(773,69,2)));
    ui->m6Buy->setText(QString::fromStdString(xmlFile.readPart(774,48,6)));
    ui->m6Sale->setText(QString::fromStdString(xmlFile.readPart(775,48,6)));
    write_M_change_Rate(776, xmlFile, 773, ui->m6cRate);
    changeColor( 6, QString::fromStdString(xmlFile.readPart(773,69,2)) );

    // Money 7
    ui->m7Name->setText("Norvec Kronu");
    ui->m7Change->setText(QString::fromStdString(xmlFile.readPart(781,69,2)));
    ui->m7Buy->setText(QString::fromStdString(xmlFile.readPart(782,48,6)));
    ui->m7Sale->setText(QString::fromStdString(xmlFile.readPart(783,48,6)));
    write_M_change_Rate(784, xmlFile, 781, ui->m7cRate);
    changeColor( 7, QString::fromStdString(xmlFile.readPart(781,69,2)) );

    // Money 8
    ui->m8Name->setText("Danimarka Kronu");
    ui->m8Change->setText(QString::fromStdString(xmlFile.readPart(789,69,2)));
    ui->m8Buy->setText(QString::fromStdString(xmlFile.readPart(790,48,6)));
    ui->m8Sale->setText(QString::fromStdString(xmlFile.readPart(791,48,6)));
    write_M_change_Rate(792, xmlFile, 789, ui->m8cRate);
    changeColor( 8, QString::fromStdString(xmlFile.readPart(789,69,2)) );

    // Money 9
    ui->m9Name->setText("Avustralya Doları");
    ui->m9Change->setText(QString::fromStdString(xmlFile.readPart(797,69,2)));
    ui->m9Buy->setText(QString::fromStdString(xmlFile.readPart(798,48,6)));
    ui->m9Sale->setText(QString::fromStdString(xmlFile.readPart(799,48,6)));
    write_M_change_Rate(800, xmlFile, 797, ui->m9cRate);
    changeColor( 9, QString::fromStdString(xmlFile.readPart(797,69,2)) );

    // Money 10
    ui->m10Name->setText("Kanada Doları");
    ui->m10Change->setText(QString::fromStdString(xmlFile.readPart(805,69,2)));
    ui->m10Buy->setText(QString::fromStdString(xmlFile.readPart(806,48,6)));
    ui->m10Sale->setText(QString::fromStdString(xmlFile.readPart(807,48,6)));
    write_M_change_Rate(808, xmlFile, 805, ui->m10cRate);
    changeColor( 10, QString::fromStdString(xmlFile.readPart(805,69,2)) );

    // Money 11
    ui->m11Name->setText("Isvec Kronu");
    ui->m11Change->setText(QString::fromStdString(xmlFile.readPart(813,69,2)));
    ui->m11Buy->setText(QString::fromStdString(xmlFile.readPart(814,48,6)));
    ui->m11Sale->setText(QString::fromStdString(xmlFile.readPart(815,48,6)));
    write_M_change_Rate(816, xmlFile, 813, ui->m11cRate);
    changeColor( 11, QString::fromStdString(xmlFile.readPart(813,69,2)) );
}

void MainWindow::changeColor(int mNumber, QString change)
{
    int temp;
    if( change == "dw" )
        temp = 1;
    else if( change == "up" )
        temp = 2;
    else if ( change == "st" )
        temp = 3;

    switch(mNumber)
    {
        case 1:         //Money 1
            switch (temp)
            {
                case 1: //red
                    ui->m1Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m1Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m1Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m1Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m1cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m1Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m1Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m1Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m1Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m1cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m1Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m1Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m1Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m1Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m1cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 2:     //Money 2
            switch (temp)
            {
                case 1: //red
                    ui->m2Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m2Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m2Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m2Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m2cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m2Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m2Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m2Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m2Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m2cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m2Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m2Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m2Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m2Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m2cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 3:     //Money 3
            switch (temp)
            {
                case 1: //red
                    ui->m3Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m3Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m3Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m3Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m3cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m4Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m4Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m4Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m4Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m4cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m5Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m5Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m5Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m5Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m5cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 4:     //Money 4
            switch (temp)
            {
                case 1: //red
                    ui->m4Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m4Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m4Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m4Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m4cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m4Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m4Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m4Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m4Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m4cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m4Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m4Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m4Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m4Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m4cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 5:     //Money 5
            switch (temp)
            {
                case 1: //red
                    ui->m5Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m5Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m5Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m5Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m5cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m5Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m5Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m5Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m5Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m5cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m5Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m5Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m5Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m5Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m5cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 6:     //Money 6
            switch (temp)
            {
                case 1: //red
                    ui->m6Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m6Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m6Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m6Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m6cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m6Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m6Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m6Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m6Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m6cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m6Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m6Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m6Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m6Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m6cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 7:     //Money 7
            switch (temp)
            {
                case 1: //red
                    ui->m7Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m7Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m7Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m7Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m7cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m7Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m7Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m7Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m7Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m7cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m7Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m7Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m7Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m7Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m7cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 8:     //Money 8
            switch (temp)
            {
                case 1: //red
                    ui->m8Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m8Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m8Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m8Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m8cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m8Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m8Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m8Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m8Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m8cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m8Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m8Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m8Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m8Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m8cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 9:     //Money 9
            switch (temp)
            {
                case 1: //red
                    ui->m9Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m9Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m9Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m9Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m9cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m9Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m9Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m9Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m9Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m9cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m9Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m9Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m9Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m9Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m9cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
                break;
        case 10:    //Money 10
            switch (temp)
            {
                case 1: //red
                    ui->m10Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m10Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m10Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m10Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m10cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m10Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m10Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m10Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m10Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m10cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m10Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m10Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m10Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m10Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m10cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
        case 11:    //Money 11
            switch (temp)
            {
                case 1: //red
                    ui->m11Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m11Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m11Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m11Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    ui->m11cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 0, 0);}"));
                    break;
                case 2: //green
                    ui->m11Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m11Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m11Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m11Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    ui->m11cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(6, 205, 26);}"));
                    break;
                case 3: //yellow
                    ui->m11Name->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m11Change->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m11Buy->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m11Sale->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    ui->m11cRate->setStyleSheet(QStringLiteral("QLabel{color: rgb(255, 255, 0);}"));
                    break;
            }
            break;
    }
}

void MainWindow::write_M_change_Rate(int ln,  parser &prs, int changeLine, QLabel *label)
{
    if( prs.readPart(changeLine,69,2) == "up" )
    {
        label->setText(QString::fromStdString("+" + prs.readRate(ln)));
    }
    else
        label->setText(QString::fromStdString(prs.readRate(ln)));

}

void MainWindow::on_autoUpdate_stateChanged()
{
    if( ui->autoUpdate->checkState() == Qt::Checked )
    {
        ui->updateButton->setDisabled(true);
        ui->statusbar->showMessage("Mode: Auto update");
        countTimer = 0;
        timer->start(5000);
    }
    else
    {
        ui->updateButton->setEnabled(true);
        ui->statusbar->showMessage("Mode: Manuel update");
        timer->stop();

    }
}

void MainWindow::update_slots()
{
    countTimer++;
    if ( countTimer == 12*(ui->updateRange->value()) )
    {
        htmll->getURL("https://www.website.com");
        ui->statusbar->showMessage("updated");
        countTimer = 0;
    }
    else
    {
        ui->statusbar->showMessage("Mode: Auto update");
    }
}

