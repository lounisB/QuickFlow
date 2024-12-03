#include "cresult.h"

Cresult::Cresult(QObject *parent)
    : QObject(parent)
{
}

Cresult::Cresult(const QString &name, const QString &value, QObject *parent)
    : QObject(parent), m_name(name), m_value(value)
{
}

QString Cresult::name() const
{
    return m_name;
}

void Cresult::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

QString Cresult::value() const
{
    return m_value;
}

void Cresult::setValue(const QString &value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged();
    }
}

QString Cresult::key() const
{
    return m_key;
}

void Cresult::setKey(const QString &key)
{
    if (key != m_key) {
        m_key = key;
        emit keyChanged();
    }
}

QString Cresult::preText() const
{
    return m_preText;
}

void Cresult::setPreText(const QString &preText)
{
    if (preText != m_preText) {
        m_preText = preText;
        emit preTextChanged();
    }
}

QString Cresult::postText() const
{
    return m_postText;
}

void Cresult::setPostText(const QString &postText)
{
    if (postText != m_postText) {
        m_postText = postText;
        emit postTextChanged();
    }
}
