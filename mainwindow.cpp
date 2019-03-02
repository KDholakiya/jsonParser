#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QTextStream>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_released()
{
    QString input= ui->input->toPlainText();
    input.push_front("\n");
    QTextStream *txt=new QTextStream(&input);
    QString output;
    while (!txt->atEnd()) {
        QString tmptxt;
        if(txt->readLine()==""){
            for(int i=0;i<7;i++){
                tmptxt.append("\""+headers[i]+"\":"+"\""+txt->readLine()+"\"");
                if(i!=6){
                    tmptxt.append(",\n");
                }
            }
            tmptxt.push_front("{");
            tmptxt.push_back("},");
            output.append(tmptxt);
        }
    }
    if(output != ""){
        output.push_front("[\n");
        output.truncate(output.lastIndexOf(QChar(',')));
        output.push_back("\n]");
        qDebug()<<output;
        ui->output->setText(output);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->input->clear();
    ui->output->clear();
    ui->lineEdit->clear();
}

void MainWindow::on_lineEdit_editingFinished()
{
    QString content=ui->lineEdit->text();
    content.push_front("/a/");
    for(int i=0;i<content.size();i++){
        QString part=content.right(content.length()-(content.lastIndexOf(QChar('/'))+1));
        content=content.remove(content.lastIndexOf(QChar('/')),content.length());
        headers.push_front(part);
    }
}
