#ifndef VOL_H
#define VOL_H
#include <QDataStream>
#include <QString>
struct vol{
    int reference;
    QString denomination;
    friend QDataStream& operator>>(QDataStream& in, vol& v) {
            in >> v.reference >> v.denomination;
            return in;
        }
};

#endif // VOL_H
