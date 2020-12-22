#include "mainwindow.h"

#include <QtWidgets>
#include <QVBoxLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    containerWidget = new QWidget();
    setCentralWidget(containerWidget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    setStatusTip("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>");

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    layout->addWidget(bottomFiller);
    containerWidget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Menus"));
    setMinimumSize(160, 160);
    resize(480, 320);
}

void MainWindow::openFile()
{
    const char *fileFilters= "Comic Book Archives (*.cbr *.cbz);;All Files (*.*)";
    curBook = QFileDialog::getOpenFileName(this,
        tr("Open Comic Book"), "/home/malay", tr(fileFilters));
    QString msg = "Opening ";
    msg.append(curBook);
    setStatusTip(msg);
}

void MainWindow::openFolder()
{
    QString curFolder = QFileDialog::getExistingDirectory(this,
        tr("Load all books from folder"),
        "/home/malay",
        QFileDialog::Options::QFlags::enum_type::ShowDirsOnly);
}

void MainWindow::quit()
{
    QApplication::quit();
}

void MainWindow::aboutQt()
{
    QApplication::aboutQt();
}

void MainWindow::createActions()
{
    fileAct = new QAction(tr("&Open File..."), this);
    fileAct->setShortcuts(QKeySequence::Open);
    fileAct->setStatusTip(tr("Open a comic book file"));
    connect(fileAct, &QAction::triggered, this, &MainWindow::openFile);

    folderAct = new QAction(tr("&Open Folder..."), this);
    folderAct->setStatusTip(tr("Open an existing folder"));
    connect(folderAct, &QAction::triggered, this, &MainWindow::openFolder);

    quitAct = new QAction(tr("E&xit"), this);
    quitAct->setShortcuts(QKeySequence::Quit);
    quitAct->setStatusTip(tr("Exit the application"));
    connect(quitAct, &QAction::triggered, this, &QWidget::close);

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, &QAction::triggered, qApp, &QApplication::aboutQt);

}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(fileAct);
    fileMenu->addAction(folderAct);
    fileMenu->addSeparator();
    fileMenu->addAction(quitAct);

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutQtAct);
}
