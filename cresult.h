#ifndef CRESULT_H
#define CRESULT_H

#include <QObject>

class Cresult : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString value READ value WRITE setValue NOTIFY valueChanged)
    Q_PROPERTY(QString key READ key WRITE setKey NOTIFY keyChanged)
    Q_PROPERTY(QString preText READ preText WRITE setPreText NOTIFY preTextChanged)
    Q_PROPERTY(QString postText READ postText WRITE setPostText NOTIFY postTextChanged)

public:
    Cresult(QObject *parent = nullptr);
    Cresult(const QString &name, const QString &value, QObject *parent=0);


    QString name() const;
    void setName(const QString &name);
    QString value() const;
    void setValue(const QString &value);
    QString key() const;
    void setKey(const QString &key);
    QString preText() const;
    void setPreText(const QString &preText);
    QString postText() const;
    void setPostText(const QString &postText);



signals:
    void nameChanged();
    void valueChanged();
    void preTextChanged();
    void postTextChanged();
    void keyChanged();

private:
    // todo to add
    //enum m_type = value or list

    QString m_name;
    QString m_value;
    QString m_key;
    QString m_preText;
    QString m_postText;


    // todo to add
    // result list
    QList<QString> m_keysList;      // keys to display if it's a list
    QList<QString> m_valuesList;    // values if it's a list

};

#endif // CRESULT_H
