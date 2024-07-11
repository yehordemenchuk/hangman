#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>

QT_BEGIN_NAMESPACE
namespace Ui 
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, QApplication* application_ptr = nullptr);
    ~MainWindow();

private slots:
    void on_playButton_clicked();

    void on_exitButton_clicked();

private:
    Ui::MainWindow *ui;
    QApplication *m_application_ptr;
};
#endif // MAINWINDOW_H
