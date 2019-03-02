#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_released();

    void on_pushButton_2_clicked();

    void on_lineEdit_editingFinished();

private:
    Ui::MainWindow *ui;
    QList<QString> headers;
};

#endif // MAINWINDOW_H
