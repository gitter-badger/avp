#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
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



void MainWindow::showMat(const Mat &mat){
    // convert Mat object to QImage object
    QImage image( mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888 );
    image = image.rgbSwapped();

    // convert QImage object to QPixmap object
    QPixmap pixmap = QPixmap::fromImage(image);

    // set QPixmap object for QLabel
    ui->imageLabel->setPixmap(pixmap);
}


void MainWindow::on_circleButton_clicked()
{
    Scalar gray = Scalar(126, 126, 126);
    Scalar black = Scalar(0, 0, 0);
    Scalar white = Scalar(255, 255, 255);
    Mat image(400, 400, CV_8UC3, gray);

    circle(image, Point(200, 200), 200, white, CV_FILLED);
    for(int i=0; i<10; i++){
        circle(image, Point(200, 200), 20*i, black);
    }
    showMat(image);
}

void MainWindow::on_dotsButton_clicked()
{
    Scalar white = Scalar(255, 255, 255);
    Mat image(400, 400, CV_8UC3, white);
    for(int i=0; i<10000; i++){
        int r = rand() % 256;
        int g = rand() % 256;
        int b = rand() % 256;
        Scalar color = Scalar(b, g, r);
        int x = rand() % 401;
        int y = rand() % 401;
        circle(image, Point(x,y), 5, color, CV_FILLED);
    }
    showMat(image);
}

void MainWindow::on_stripsButton_clicked()
{
    Scalar gray = Scalar(126, 126, 126);
    Scalar black = Scalar(0, 0, 0);
    Scalar white = Scalar(255, 255, 255);
    Mat image(400, 400, CV_8UC3, gray);
    for(int i=0; i<20; i++){
        if (i%2 == 0) {
            rectangle(image, Point(20*i, 0), Point(20+i*20, 400), black, CV_FILLED);
        }else {
            rectangle(image, Point(20*i, 0), Point(20+i*20, 400), white, CV_FILLED);
        }

    }
    showMat(image);
}

void MainWindow::on_chessButton_clicked()
{
    Scalar gray = Scalar(126, 126, 126);
    Scalar black = Scalar(0, 0, 0);
    Scalar white = Scalar(255, 255, 255);
    Mat image(400, 400, CV_8UC3, gray);

    for(int x=0; x<8; x++){
        for(int y=0; y<8; y++){
            if(x % 2 == 0 ^ y % 2 == 0){
                rectangle(image, Point(50*y, 0+50*x), Point(50+y*50, 50+50*x), black, CV_FILLED);
            }else {
                rectangle(image, Point(50*y, 0+50*x), Point(50+y*50, 50+50*x), white, CV_FILLED);
            }

        }
    }

    showMat(image);
}

void MainWindow::on_coloredchessButton_clicked()
{
    Scalar gray = Scalar(126, 126, 126);
    Mat image(400, 400, CV_8UC3, gray);

    for(int x=0; x<8; x++){
        for(int y=0; y<8; y++){
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            Scalar color = Scalar(b, g, r);
            rectangle(image, Point(50*y, 0+50*x), Point(50+y*50, 50+50*x), color, CV_FILLED);
        }
    }

    showMat(image);
}
