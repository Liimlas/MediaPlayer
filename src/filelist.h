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
    void viewSongData(QString, QLabel *);
    bool updateSongData(QString);
    bool setCoverImage(QString);
private:
    QFileSystemModel *model;
};

#endif // FILELIST_H
