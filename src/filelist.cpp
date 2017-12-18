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
}

QString FileList::getSongPath(const QModelIndex &index){
    QString filepath = model->filePath(index);
    return filepath;
}

void FileList::viewSongData(QString filepath, QLabel *label){
    TagLib::FileRef file(filepath.toLatin1());
    auto text = file.tag()->artist() +"\n"+ file.tag()->title().toCString() + "\n" + file.tag()->album().toCString();
    label->setText(QString(text.toCString()));
}

bool FileList::updateSongData(QString file){
    return true;
}
