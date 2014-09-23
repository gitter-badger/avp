#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv2/opencv.hpp>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_circleButton_clicked();

    void on_dotsButton_clicked();

    void on_stripsButton_clicked();

    void on_chessButton_clicked();

    void on_coloredchessButton_clicked();

    void on_imgButton_clicked();

private:
    void testImage();
    void showMat(const cv::Mat& mat);
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
