#include "cvariable.h"


Cvariable::Cvariable(QObject *parent)
    : QObject(parent)
{
}

Cvariable::Cvariable(const QString &name, const QString &value, QObject *parent)
    : QObject(parent), m_name(name), m_value(value)
{
}

QString Cvariable::name() const
{
    return m_name;
}

void Cvariable::setName(const QString &name)
{
    if (name != m_name) {
        m_name = name;
        emit nameChanged();
    }
}

QString Cvariable::value() const
{
    return m_value;
}

void Cvariable::setValue(const QString &value)
{
    if (value != m_value) {
        m_value = value;
        emit valueChanged();
    }
}
