#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
    {
        ui->setupUi(this);
    }

MainWindow::~MainWindow()
    {
        delete ui;
    }

void MainWindow::setEspressione(QString num)
    {
        QString sCount = ui -> Espressione ->text();
        if (num == "+" ||
            num == "*" ||
            num == "-" ||
            num == ":")
            {
                sCount = sCount + " " + num + " ";
            }
        else
            {
                sCount = sCount + num;
            }
        ui -> Espressione -> setText(sCount);
    }

void MainWindow::CalcolaRisultato()
    {
        double numero = RilevateNum(1);
        for (int i = 1; i < RilevateSignNum() + 1; i++)
            {
                if (RilevateSign(i) == "+")
                    {
                        numero += RilevateNum(i + 1);
                    }
                else if (RilevateSign(i) == "-")
                    {
                        numero -= RilevateNum(i + 1);
                    }
            }
        ui -> Espressione -> setText(QString("%1").arg(numero));
    }

double MainWindow::RilevateNum(short num)
    {
        QString espressione = ui -> Espressione -> text() + " ";
        QString SNumero;

        int numeroCifre = 0;
        int numero = 0;
        num = num * 2 - 1;

        for (int i = 0; i < espressione.size(); i++)
            {
                numeroCifre++;
                if (espressione[i] == " ")
                    {
                        num--;
                        if (num == 0)
                            {
                                for (int j = 0; j < numeroCifre - 1; j++)
                                    {
                                        SNumero[j] = espressione[j + i - numeroCifre + 1];
                                    }

                                numero = QString(SNumero).toDouble();
                                return numero;
                            }
                        else if (espressione[i - 1] == "+" ||
                                 espressione[i - 1] == "-" ||
                                 espressione[i - 1] == "*" ||
                                 espressione[i - 1] == ":")
                            {
                                numeroCifre = 0;
                            }
                    }
            }
        return NULL;
    }

QString MainWindow::RilevateSign(double sign)
    {
        QString espressione = ui -> Espressione -> text() + " ";
        for (int i = 0; i < espressione.size(); i++)
            {
                if (espressione[i] == "+" ||
                    espressione[i] == "-" ||
                    espressione[i] == "*" ||
                    espressione[i] == ":")
                    {
                        sign--;
                        if (sign == 0)
                            return QString("%1").arg(espressione[i]);
                    }
            }
        return " ";
    }

double MainWindow::RilevateSignNum()
    {
        QString espressione = ui -> Espressione -> text() + " ";
        int sign = 0;
        for (int i = 0; i < espressione.size(); i++)
            {
                if (espressione[i] == "+" ||
                    espressione[i] == "-" ||
                    espressione[i] == "*" ||
                    espressione[i] == ":")
                    {
                        sign++;
                    }
            }
        return sign;
    }

void MainWindow::on_Uno_clicked()
    {
        setEspressione("1");
    }

void MainWindow::on_Due_clicked()
    {
        setEspressione("2");
    }

void MainWindow::on_Tre_clicked()
    {
        setEspressione("3");
    }

void MainWindow::on_Quattro_clicked()
    {
        setEspressione("4");
    }

void MainWindow::on_Cinque_clicked()
    {
        setEspressione("5");
    }

void MainWindow::on_Sei_clicked()
    {
        setEspressione("6");
    }

void MainWindow::on_Sette_clicked()
    {
        setEspressione("7");
    }

void MainWindow::on_Otto_clicked()
    {
        setEspressione("8");
    }

void MainWindow::on_Nove_clicked()
    {
        setEspressione("9");
    }

void MainWindow::on_Zero_clicked()
    {
        setEspressione("0");
    }

void MainWindow::on_Piu_clicked()
    {
        setEspressione("+");
    }

void MainWindow::on_Meno_clicked()
    {
        setEspressione("-");
    }

void MainWindow::on_Per_clicked()
    {
        setEspressione("*");
    }

void MainWindow::on_Diviso_clicked()
    {
        setEspressione(":");
    }

void MainWindow::on_Uguale_clicked()
    {
        CalcolaRisultato();
    }
