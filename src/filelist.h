#ifndef FILELIST_H
#define FILELIST_H
#include <QFileSystemModel>
#include <QTreeView>
class FileList
{
public:
    FileList(QTreeView*);
    ~FileList();
private:
    QFileSystemModel *model;
};

#endif // FILELIST_H
