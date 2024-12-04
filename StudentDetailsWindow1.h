#ifndef STUDENTDETAILSWINDOW1_H
#define STUDENTDETAILSWINDOW1_H

#include <QWidget>
#include "ui_StudentDetailsWindow1.h"
#include <QTableWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <vector>
#include "Grades.h"

class StudentDetailsWindow1 : public QWidget
{
	Q_OBJECT

public:
	StudentDetailsWindow1(QWidget *parent = nullptr);
	

	void setStudentData(const std::vector<Grades>& students, const QString& currentStudentAverage, int currentStudentGroup);

private:
	Ui::StudentDetailsWindow1Class ui;
	QTableWidget* studentTable;
	QLabel* groupAverageLabel;
	QLabel* currentStudentLabel;
};

#endif // STUDENTDETAILSWINDOW1_H
#pragma once
