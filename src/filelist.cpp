#include "filelist.h"
#include <iostream>
#include <QStandardPaths>
#include <attachedpictureframe.h>
#include <id3v2tag.h>
#include <mpegfile.h>
FileList::FileList(QTreeView *parent)
{
    model = new QFileSystemModel;
    QModelIndex idx = model->index(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    model->setRootPath(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    parent->setModel(model);
    parent->setRootIndex(idx);

    parent->setSortingEnabled(true);
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
