#ifndef CVARIABLE_H
#define CVARIABLE_H

#include <QObject>

class Cvariable : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)

public:
    Cvariable(QObject *parent = nullptr);
    Cvariable(const QString &name, const QString &value, QObject *parent=0);

    QString name() const;
    void setName(const QString &name);
    QString value() const;
    void setValue(const QString &value);

signals:
    void nameChanged();
    void valueChanged();

private:
    QString m_name;
    QString m_value;

};

#endif // CVARIABLE_H
