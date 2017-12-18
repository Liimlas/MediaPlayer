#ifndef FILELIST_H
#define FILELIST_H
#include <QFileSystemModel>
#include <QTreeView>
#include <QLabel>
#include <tag.h>
#include <fileref.h>

class FileList
{
public:
    FileList(QTreeView*);
    ~FileList();
    QString getSongPath(const QModelIndex &);
    TagLib::Tag* getCurrentTag();
    void saveMetadata();
private:
    QFileSystemModel *model;
    TagLib::FileRef *file = nullptr;
};

#endif // FILELIST_H
