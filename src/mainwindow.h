#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "BoxDemo.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *event);
    QPaintEngine * paintEngine() const;

    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);

    void keyPressEvent(QKeyEvent *event);
private:
    Ui::MainWindow *ui;

    std::shared_ptr<BoxDemo> g_pBoxDemo;

    bool        b_mouseIsP;
    QPoint      m_orginP;

    QTimer          *mGameTimer;

    PAINTSTRUCT ps;
};

#endif // MAINWINDOW_H
