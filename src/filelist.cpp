#include "filelist.h"
#include <iostream>
#include <QStandardPaths>

FileList::FileList(QTreeView *parent)
{
    model = new QFileSystemModel;
    QModelIndex idx = model->index(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    model->setRootPath(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    parent->setModel(model);
    parent->setRootIndex(idx);
}
FileList::~FileList() {
    delete(model);
}

QString FileList::getSongPath(const QModelIndex &index){
    return model->filePath(index);
}
