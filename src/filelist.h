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
    void changeDirectory(QString path);
    QString getCurrentDirectory();
private:
    QFileSystemModel *model;
    QTreeView *tree;
    TagLib::FileRef *file = nullptr;
    QString currentDirectory;
};

#endif // FILELIST_H
