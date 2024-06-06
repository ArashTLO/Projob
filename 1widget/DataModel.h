#ifndef DATAMODEL_H
#define DATAMODEL_H
#include "QString"
#endif // DATAMODEL_H
class DataModel {
public:
    QString getFirstname() const { return firstname_; }
    void setFirstname(const QString& firstname) { firstname_ = firstname; }
    QString getLastname() const { return lastname_; }
    void setLastname(const QString& lastname) { lastname_ = lastname; }
    QString getEmployment() const { return employment_; }
    void setEmployment(const QString& employment) { employment_ = employment; }
private:
    QString firstname_;
    QString lastname_;
    QString employment_;
};

