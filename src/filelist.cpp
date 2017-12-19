#include "filelist.h"
#include <QStandardPaths>
#include <QStringList>

FileList::FileList(QTreeView *parent)
{
    model = new QFileSystemModel;
    tree = parent;
    currentDirectory = QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath());
    QModelIndex const idx = model->index(currentDirectory);
    model->setRootPath(currentDirectory);
    tree->setModel(model);
    tree->setRootIndex(idx);
    tree->setSortingEnabled(true);

    model->setFilter(QDir::NoDotAndDotDot|QDir::Files);
    model->setNameFilterDisables(false);
    model->setNameFilters(QStringList() << "*.mp3" << "*.wav" << "*.ogg");
}

void FileList::onSearch(QString search)
{
    model->setNameFilters(QStringList() << ("*" + search + "*.mp3") << ("*" + search + "*.wav") << ("*" + search + "*.ogg"));
}

FileList::~FileList() {
    delete(model);
    delete(file);
}

QString FileList::getSongPath(const QModelIndex &index){
    QString filepath = model->filePath(index);
    if(file != nullptr){
        delete(file);
    }
    file = new TagLib::FileRef(filepath.toStdString().c_str());
    return filepath;
}
void FileList::saveMetadata(){
    if(file != nullptr){
        file->save();
    }
}
TagLib::Tag *FileList::getCurrentTag(){
    return file->tag();
}

void FileList::changeDirectory(QString path){
    currentDirectory = path;
    QModelIndex const idx = model->index(currentDirectory);
    model->setRootPath(currentDirectory);
    tree->setModel(model);
    tree->setRootIndex(idx);
}

QString FileList::getCurrentDirectory(){
    return currentDirectory;
}
