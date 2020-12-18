#include <QCoreApplication>
#include <QDir>

#include <kzip.h>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QStringList args(app.arguments());

    if (args.size() != 2) {
        // Too many or too few arguments
        qWarning("Usage: ./unzipper <archive.zip>");
        return 1;
    }

    QString file = args.at(1);
    KZip archive(file);

    // Open the archive
    if (!archive.open(QIODevice::ReadOnly)) {
        qWarning("Cannot open " + file.toLatin1());
        qWarning("Is it a valid zip file?");
        return 1;
    }

    // Take the root folder from the archive and create a KArchiveDirectory object.
    // KArchiveDirectory represents a directory in a KArchive.
    const KArchiveDirectory *root = archive.directory();

    // We can extract all contents from a KArchiveDirectory to a destination.
    // recursive true will also extract subdirectories.
    QString destination = QDir::currentPath();
    bool recursive = true;
    root->copyTo(destination, recursive);

    archive.close();
    return 0;
}
