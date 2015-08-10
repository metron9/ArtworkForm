#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include <QPointer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    enum Htmltags {h1,h2,h3,h4,h5,h6};

    QString textAt(Htmltags,int i,QString);
    QString nbsp(int i);


private slots:
    void on_pushButton_clicked();

    void on_textBrowser_destroyed();

    void on_checkBox_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
