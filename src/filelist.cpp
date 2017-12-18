#include "filelist.h"
#include <iostream>
#include <QStandardPaths>
#include <QStringList>

FileList::FileList(QTreeView *parent)
{
    model = new QFileSystemModel;
    QModelIndex const idx = model->index(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    model->setRootPath(QStandardPaths::standardLocations(QStandardPaths::MusicLocation).value(0, QDir::homePath()));
    parent->setModel(model);
    parent->setRootIndex(idx);
    parent->setSortingEnabled(true);

    QStringList NameList("dankshit.wav");
    NameList.append("Seppo");

    auto filter = model->filter();
    model->setFilter(filter);
    model->setNameFilters(NameList);

}

FileList::~FileList() {
    delete(model);
}

QString FileList::getSongPath(const QModelIndex &index){
    return model->filePath(index);
}
