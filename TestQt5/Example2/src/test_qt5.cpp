/*

Testing the C++ Qt5

*/

#include <iostream> // std::cout

#include <QApplication> // Qt5

// #include <QMainWindow>
#include "mainwindow.h"

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Qt5 Example 2:" << endl;
    cout << "---------------------" << endl;

    cout << "" << endl;

    QApplication app(argc, argv);

    // Using QMainWindows directly
    // QMainWindow main_window;
    // main_window.setWindowTitle("Qt5 Example 2");
    // main_window.setMinimumSize(400, 400);
    // main_window.show();

    // Using derived QMainWindow
    MainWindow main_window;
    main_window.show();

    return app.exec();
}