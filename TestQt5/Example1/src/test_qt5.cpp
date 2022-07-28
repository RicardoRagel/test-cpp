/*

Testing the C++ Qt5

*/

#include <iostream> // std::cout

#include <QApplication> // Qt5
#include <QLabel>
#include <QWidget>

// Aliases
using namespace std;

int main(int argc, char **argv)
{
    cout << endl;
    cout << "(main) Qt5 Example 1:" << endl;
    cout << "---------------------" << endl;

    cout << "" << endl;

    QApplication app(argc, argv);
 
    QLabel label("<center>Using CMake to compile a Qt5 Project</center>");
    label.setWindowTitle("Qt5 Example");
    label.resize(400, 400);
    label.show();

    return app.exec();
}