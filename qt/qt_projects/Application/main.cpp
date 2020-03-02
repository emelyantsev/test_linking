
#include <QtWidgets>

// ----------------------------------------------------------------------
int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QLabel   lbl("this is an example text");
    QLibrary lib("dynlib");

    lbl.setText(lbl.text());

    typedef QString (*Fct) (const QString&);

    Fct fct = (Fct) lib.resolve("oddUpper");

    if (fct) {

        lbl.setText(fct(lbl.text()));
    }

    lbl.resize(250, 50);

    lbl.show();

    return app.exec();
}
