#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <libloaderapi.h>
#include <WinUser.h>
#include <windef.h>
#include <QMouseEvent>
#include <QTimer>
#include <QKeyEvent>

static HDC s_hdcBackbuffer;			//后缓冲设备句柄
static HBITMAP s_hBitmap;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    g_pBoxDemo(std::make_shared<BoxDemo>()),
    b_mouseIsP(false)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_PaintOnScreen, true);

    g_pBoxDemo->Init(GetModuleHandleA(""), (HWND)this->winId());

    mGameTimer = new QTimer(this);
    mGameTimer->start(10);
    connect(mGameTimer, &QTimer::timeout, this, [&](){
         this->repaint();
    });


    BITMAPINFOHEADER bmphdr = { 0 };
    bmphdr.biSize = sizeof(BITMAPINFOHEADER);
    bmphdr.biWidth = this->width();
    bmphdr.biHeight = this->height();
    bmphdr.biPlanes = 1;
    bmphdr.biBitCount = 32;
    bmphdr.biSizeImage = this->width() * this->height() * 4;

    //获得前置缓冲区dc
    HDC hdc = GetDC((HWND)this->winId());
    //创建后缓冲区
    //先创建一个内存dc
    s_hdcBackbuffer = CreateCompatibleDC(hdc);


    if (!(s_hBitmap = CreateDIBSection(hdc, (PBITMAPINFO)&bmphdr, DIB_RGB_COLORS,
                                       reinterpret_cast<void**>(&g_pBoxDemo->GetDevice()->GetFrameBuffer()), nullptr, 0)))
    {
        //MessageBox(nullptr, "create dib section failed!", "error", MB_OK);
    }

    //将bitmap装入内存dc
    (HBITMAP)SelectObject(s_hdcBackbuffer, s_hBitmap);
    ReleaseDC((HWND)this->winId(), hdc);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    g_pBoxDemo->Update(0.f);
    g_pBoxDemo->Render();

    //把backbuffer内容传到frontbuffer
    BeginPaint((HWND)this->winId(), &ps);
    BitBlt(GetDC((HWND)this->winId()), 0, 0, this->width(), this->height(), s_hdcBackbuffer,   0, 0, SRCCOPY);
    EndPaint((HWND)this->winId(), &ps);

//    QImage img = QtWin::imageFromHBITMAP(GetDC((HWND)this->winId()), s_hBitmap, this->width(), this->height());

//    InvalidateRect ((HWND)this->winId(), nullptr, true) ;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    m_orginP = event->globalPos();

    g_pBoxDemo.get()->OnMouseDown(WPARAM(this->winId()), this->pos().x(),this->pos().y());
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    g_pBoxDemo.get()->OnMouseUp(WPARAM(this->winId()), 0,0);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint thepos = event->globalPos() - m_orginP;
    g_pBoxDemo.get()->OnMouseMove(WPARAM(this->winId()), thepos.x(), -thepos.y());
    repaint();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_W :
        g_pBoxDemo.get()->Walk(WPARAM(this->winId()), 1);
        break;
    case Qt::Key_S :
        g_pBoxDemo.get()->Walk(WPARAM(this->winId()), -1);
        break;
    case Qt::Key_A :
        g_pBoxDemo.get()->Strafe(WPARAM(this->winId()), -1);
        break;
    case Qt::Key_D :
        g_pBoxDemo.get()->Strafe(WPARAM(this->winId()), 1);
        break;
    }
}

QPaintEngine * MainWindow::paintEngine() const
{
    return nullptr;
}
