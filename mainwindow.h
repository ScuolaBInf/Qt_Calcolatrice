#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui
    {
        class MainWindow;
    }

class MainWindow : public QMainWindow
    {
        Q_OBJECT

        public:
            explicit MainWindow(QWidget *parent = 0);
            ~MainWindow();

        private slots:
            void on_Uno_clicked();
            void on_Due_clicked();
            void on_Tre_clicked();
            void on_Quattro_clicked();
            void on_Cinque_clicked();
            void on_Sei_clicked();
            void on_Sette_clicked();
            void on_Otto_clicked();
            void on_Nove_clicked();
            void on_Zero_clicked();

            void on_Piu_clicked();
            void on_Meno_clicked();
            void on_Per_clicked();
            void on_Diviso_clicked();
            void on_Uguale_clicked();

private:
            Ui::MainWindow *ui;
            void setEspressione(QString num);
            void CalcolaRisultato();
            double RilevateNum(short num);
            QString RilevateSign(double sing);
            double RilevateSignNum();
    };

#endif // MAINWINDOW_H
