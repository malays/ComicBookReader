#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QObject>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    // setup
    void createActions();
    void createMenus();

    QMenu *fileMenu;
    QAction *fileAct;
    QAction *folderAct;
    QAction *quitAct;
    QMenu *helpMenu;
    QAction *aboutQtAct;
    QWidget *containerWidget;

    // state
    QString curBook;
signals:

private slots:
    void openFile();
    void openFolder();
    void quit();
    void aboutQt();
};

#endif // MAINWINDOW_H
