#include "filelist.h"
#include <iostream>
FileList::FileList(QTreeView *parent)
{
    model = new QFileSystemModel;
    QModelIndex idx = model->index(QDir::homePath().append("/Music"));
    parent->setModel(model);
    parent->setRootIndex(idx);
}
FileList::~FileList() {
    delete(model);
}
