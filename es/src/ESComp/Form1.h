#pragma once

#include <algorithm>
#include <iterator>
#include <map>
#include <string>

namespace ESComp {

	using namespace std;

	static int Y;


	//-------------------------

	multimap<string, string> DBKnowledge;
    multimap<string, string> DBRules;
	map<string, double> DBProbability;
	map<string, double> DBResult;

    string localResult = "";
    string Result = "?";
    string firstQuestion = "";
    double Probability = 1.0;
	map<int, string> localQ;

	//--------------------------------

		

	//-------------------------------


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			//----------------------------

			DBRules.insert(pair<string, string>
                               ("���������� ������ ������� + �� (���� ������� ��������� (� ���������� �����)) + �� (���� ������� ��������� (� ���������� �����))",
                                "�������� ���� ������� (� ���������� �����)."));

            DBRules.insert(pair<string, string>
                               ("���������� ������ ������� + �� (���� ������� ��������� (� ���������� �����)) + ��� (���� ������� �� ��������� (� ���������� �����)) + �� (����� � ��������� ����� ����������� ���������) + �� (���� ����� �������� ����� ���� ����� � ��������� �����) + �� (���� �������� �� ��������� ����� � ��������� �����)",
                                "�������� ����� (����� ����� ����� � ��������� ������)."));

            DBRules.insert(pair<string, string>
                               ("���������� ������ ������� + �� (���� ������� ��������� (� ���������� �����)) + ��� (���� ������� �� ��������� (� ���������� �����)) + �� (����� � ��������� ����� ����������� ���������) + �� (���� ����� �������� ����� ���� ����� � ��������� �����) + ��� (��� �������� �� ��������� ����� � ��������� �����)",
                                "�������� ����� (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� ������ ������� + �� (���� ������� ��������� (� ���������� �����)) + ��� (���� ������� �� ��������� (� ���������� �����)) + �� (����� � ��������� ����� ����������� ���������) + ��� (��� ������ �������� ����� ���� ����� � ��������� �����)",
                                "�������� ���� ������� (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� ������ ������� + �� (���� ������� ��������� (� ���������� �����)) + ��� (���� ������� �� ��������� (� ���������� �����)) + ��� (����� � ��������� ����� ����������� �� ���������)",
                                "���������� ����� � ��������� ����� ���������."));

            DBRules.insert(pair<string, string>
                               ("���������� ������ ������� + ��� (���� ������� �� ��������� (� ���������� �����))",
                                "���������� ���� ������� � ���������� �����."));

            DBRules.insert(pair<string, string>
                               ("���������� ������ ��������� ���� + �� (���� ������� ��������� (� ��������)) + �� (���� ������� ��������� (� ��������))",
                                "�������� ���� ������� (� ��������)."));

            DBRules.insert(pair<string, string>
                               ("���������� ������ ��������� ���� + �� (���� ������� ��������� (� ��������)) + ��� (���� ������� �� ��������� (� ��������))",
                                "�������� ������� (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� ������ ��������� ���� + ��� (���� ������� �� ��������� (� ��������))",
                                "���������� ���� ������� (� ��������)."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + �� (������������ ������� �����������) + �� (������� �� �������� ������������ ���������)",
                                "������������ ��������� ��������. ������ �� � ������."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + �� (������������ ������� �����������) + ��� (������� �� �������� ������������ �� ���������) + ��� (��� �������� �� ����� �����)",
                                "�������� ����� ����� (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + �� (������������ ������� �����������) + ��� (������� �� �������� ������������ �� ���������) + �� (���� �������� �� ����� �����)",
                                "�������� ����� ����� (����� ����� ����� � ��������� ������)."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + �� (������������ ������� �����������) + ��� (������� �� �������� ������������ �� ���������) + �� �������� (���������� ���� �� �������� �� ����� �����)",
                                "�������� ����� ����� (������ ����� ����� (��������))."));
			DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + �� (������������ ������� �����������) + ��� (������� �� �������� ������������ �� ���������) + �� �������� (���������� ���� �� �������� �� ����� �����)",
                                "������������� ��������� ������� � ��������� ������ (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + ��� (������������ ������� �� �����������) + ���������� Award BIOS + ��������� ���� ������ 3 ������� �������",
                                "���������� ���������� ����������  (������� ����������� ����� � ��������� ����� ��� ������ ����� ����������� �����, ������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + ��� (������������ ������� �� �����������) + ���������� Award BIOS + ��������� ���� ������ 1 ������� � 1 �������� ������",
                                "�������� ����������� ������ (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + ��� (������������ ������� �� �����������) + ���������� Ami BIOS + ��������� ���� ������ 4 �������� �������",
                                "���������� ��������� ������ (������� ����������� ����� � ��������� ����� ��� ������ ����� ����������� �����, ������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + ��� (������������ ������� �� �����������) + ���������� Ami BIOS + ��������� ���� ������ 5 �������� �������",
                                "�������� ����������� ��������� (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("���������� � ��������� ���� � ������� + ��� (������������ ������� �� �����������) + ���������� Ami BIOS + ��������� ���� ������ 7 �������� �������",
                                "�������� ����������� ����� (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("�� ���������� ��������� ���� � �� ���������� ������� + �� (���� �������������) + ��� (������� ������ �� �������)",
                                "�������� ������� ������."));

            DBRules.insert(pair<string, string>
                               ("�� ���������� ��������� ���� � �� ���������� ������� + �� (���� �������������) + ��, �� �� ����� ��������� �� ��� (������� ������ �������, �� �� ����� ���������)",
                                "�������� ������� ������ (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("�� ���������� ��������� ���� � �� ���������� ������� + �� (���� �������������) + �� (������� ������ �������) + �� (���� ������� �������� ������� ���������)",
                                "�������� ������� ������ (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("�� ���������� ��������� ���� � �� ���������� ������� + �� (���� �������������) + �� (������� ������ �������) + ��� (���� ������� �������� ������� �� ���������)",
                                "�������� ������� ������ (������ ����� ����� (��������))."));

            DBRules.insert(pair<string, string>
                               ("�� ���������� ��������� ���� � �� ���������� ������� + ��� (��� �������������)",
                                "��������� ��������� �������������."));

			DBKnowledge.insert(pair<string, string>("���������� �� ��������� ���� � �������?", "���������� ������ �������"));
			DBKnowledge.insert(pair<string, string>("���������� ������ �������", "��������� �� ���� ������� (� ���������� �����)?"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� ������� (� ���������� �����)?", "�� (���� ������� ��������� (� ���������� �����))"));
			DBKnowledge.insert(pair<string, string>("�� (���� ������� ��������� (� ���������� �����))", "��������� �� ���� ������� (� ���������� �����)?"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� ������� (� ���������� �����)?", "�� (���� ������� ��������� (� ���������� �����))"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� ������� (� ���������� �����)?", "��� (���� ������� �� ��������� (� ���������� �����))"));
			DBKnowledge.insert(pair<string, string>("��� (���� ������� �� ��������� (� ���������� �����))", "��������� �� ����������� ����� � ��������� �����?"));
			DBKnowledge.insert(pair<string, string>("��������� �� ����������� ����� � ��������� �����?", "�� (����� � ��������� ����� ����������� ���������)"));
			DBKnowledge.insert(pair<string, string>("�� (����� � ��������� ����� ����������� ���������)", "���� �� ����� �������� ����� ���� ����� � ��������� �����?"));
			DBKnowledge.insert(pair<string, string>("���� �� ����� �������� ����� ���� ����� � ��������� �����?", "�� (���� ����� �������� ����� ���� ����� � ��������� �����)"));
			DBKnowledge.insert(pair<string, string>("�� (���� ����� �������� ����� ���� ����� � ��������� �����)", "���� �� �������� �� ��������� ����� � ��������� �����?"));
			DBKnowledge.insert(pair<string, string>("���� �� �������� �� ��������� ����� � ��������� �����?", "�� (���� �������� �� ��������� ����� � ��������� �����)"));
			DBKnowledge.insert(pair<string, string>("���� �� �������� �� ��������� ����� � ��������� �����?", "��� (��� �������� �� ��������� ����� � ��������� �����)"));
			DBKnowledge.insert(pair<string, string>("���� �� ����� �������� ����� ���� ����� � ��������� �����?", "��� (��� ������ �������� ����� ���� ����� � ��������� �����)"));
			DBKnowledge.insert(pair<string, string>("��������� �� ����������� ����� � ��������� �����?", "��� (����� � ��������� ����� ����������� �� ���������)"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� ������� (� ���������� �����)?", "��� (���� ������� �� ��������� (� ���������� �����))"));
			DBKnowledge.insert(pair<string, string>("���������� �� ��������� ���� � �������?", "���������� ������ ��������� ����"));
			DBKnowledge.insert(pair<string, string>("���������� ������ ��������� ����", "��������� �� ���� ������� (� ��������)?"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� ������� (� ��������)?", "�� (���� ������� ��������� (� ��������))"));
			DBKnowledge.insert(pair<string, string>("�� (���� ������� ��������� (� ��������))", "��������� �� ���� �������(� ��������)?"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� �������(� ��������)?", "�� (���� ������� ��������� (� ��������))"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� �������(� ��������)?", "��� (���� ������� �� ��������� (� ��������))"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� ������� (� ��������)?", "��� (���� ������� �� ��������� (� ��������))"));
			DBKnowledge.insert(pair<string, string>("���������� �� ��������� ���� � �������?", "���������� � ��������� ���� � �������"));
			DBKnowledge.insert(pair<string, string>("���������� � ��������� ���� � �������", "����������� �� ������������ �������?"));
			DBKnowledge.insert(pair<string, string>("����������� �� ������������ �������?", "�� (������������ ������� �����������)"));
			DBKnowledge.insert(pair<string, string>("�� (������������ ������� �����������)", "��������� �� ������������ ������� �� ��������?"));
			DBKnowledge.insert(pair<string, string>("��������� �� ������������ ������� �� ��������?", "�� (������� �� �������� ������������ ���������)"));
			DBKnowledge.insert(pair<string, string>("��������� �� ������������ ������� �� ��������?", "��� (������� �� �������� ������������ �� ���������)"));
			DBKnowledge.insert(pair<string, string>("��� (������� �� �������� ������������ �� ���������)", "���� �� �������� �� ����� �����?"));
			DBKnowledge.insert(pair<string, string>("���� �� �������� �� ����� �����?", "��� (��� �������� �� ����� �����)"));
			DBKnowledge.insert(pair<string, string>("���� �� �������� �� ����� �����?", "�� (���� �������� �� ����� �����)"));
			DBKnowledge.insert(pair<string, string>("���� �� �������� �� ����� �����?", "�� �������� (���������� ���� �� �������� �� ����� �����)"));
			DBKnowledge.insert(pair<string, string>("����������� �� ������������ �������?", "��� (������������ ������� �� �����������)"));
			DBKnowledge.insert(pair<string, string>("��� (������������ ������� �� �����������)", "����� ���������� BIOS?"));
			DBKnowledge.insert(pair<string, string>("����� ���������� BIOS?", "���������� Award BIOS"));
			DBKnowledge.insert(pair<string, string>("���������� Award BIOS", "������� �������� ������ ��������� ���� Award?"));
			DBKnowledge.insert(pair<string, string>("������� �������� ������ ��������� ���� Award?", "��������� ���� ������ 3 ������� �������"));
			DBKnowledge.insert(pair<string, string>("������� �������� ������ ��������� ���� Award?", "��������� ���� ������ 1 ������� � 1 �������� ������"));
			DBKnowledge.insert(pair<string, string>("����� ���������� BIOS?", "���������� Ami BIOS"));
			DBKnowledge.insert(pair<string, string>("���������� Ami BIOS", "������� �������� ������ ��������� ���� Ami?"));
			DBKnowledge.insert(pair<string, string>("������� �������� ������ ��������� ���� Ami?", "��������� ���� ������ 4 �������� �������"));
			DBKnowledge.insert(pair<string, string>("������� �������� ������ ��������� ���� Ami?", "��������� ���� ������ 5 �������� �������"));
			DBKnowledge.insert(pair<string, string>("������� �������� ������ ��������� ���� Ami?", "��������� ���� ������ 7 �������� �������"));
			DBKnowledge.insert(pair<string, string>("���������� �� ��������� ���� � �������?", "�� ���������� ��������� ���� � �� ���������� �������"));
			DBKnowledge.insert(pair<string, string>("�� ���������� ��������� ���� � �� ���������� �������", "���� �� �������������?"));
			DBKnowledge.insert(pair<string, string>("���� �� �������������?", "�� (���� �������������)"));
			DBKnowledge.insert(pair<string, string>("�� (���� �������������)", "������� �� ������� ������?"));
			DBKnowledge.insert(pair<string, string>("������� �� ������� ������?", "��� (������� ������ �� �������)"));
			DBKnowledge.insert(pair<string, string>("������� �� ������� ������?", "��, �� �� ����� ��������� �� ��� (������� ������ �������, �� �� ����� ���������)"));
			DBKnowledge.insert(pair<string, string>("������� �� ������� ������?", "�� (������� ������ �������)"));
			DBKnowledge.insert(pair<string, string>("�� (������� ������ �������)", "��������� �� ���� �������� �������?"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� �������� �������?", "�� (���� ������� �������� ������� ���������)"));
			DBKnowledge.insert(pair<string, string>("��������� �� ���� �������� �������?", "��� (���� ������� �������� ������� �� ���������)"));
			DBKnowledge.insert(pair<string, string>("���� �� �������������?", "��� (��� �������������)"));

			DBProbability.insert(pair<string, double>("���������� ������ �������", 0.98));
			DBProbability.insert(pair<string, double>("���������� ������ ��������� ����", 0.98));
			DBProbability.insert(pair<string, double>("�� (���� ������� ��������� (� ���������� �����))", 0.98));
			DBProbability.insert(pair<string, double>("�� (���� ������� ��������� (� ���������� �����))", 0.88));
			DBProbability.insert(pair<string, double>("��� (���� ������� �� ��������� (� ���������� �����))", 0.98));
			DBProbability.insert(pair<string, double>("�� (����� � ��������� ����� ����������� ���������)", 0.98));
			DBProbability.insert(pair<string, double>("�� (���� ����� �������� ����� ���� ����� � ��������� �����)", 0.98));
			DBProbability.insert(pair<string, double>("�� (���� �������� �� ��������� ����� � ��������� �����)", 0.92));
			DBProbability.insert(pair<string, double>("��� (��� �������� �� ��������� ����� � ��������� �����)", 0.98));
			DBProbability.insert(pair<string, double>("��� (��� ������ �������� ����� ���� ����� � ��������� �����)", 0.98));
			DBProbability.insert(pair<string, double>("��� (����� � ��������� ����� ����������� �� ���������)", 0.96));
			DBProbability.insert(pair<string, double>("��� (���� ������� �� ��������� (� ���������� �����))", 0.98));
			DBProbability.insert(pair<string, double>("�� (���� ������� ��������� (� ��������))", 0.98));
			DBProbability.insert(pair<string, double>("�� (���� ������� ��������� (� ��������))", 0.98));
			DBProbability.insert(pair<string, double>("��� (���� ������� �� ��������� (� ��������))", 0.98));
			DBProbability.insert(pair<string, double>("��� (���� ������� �� ��������� (� ��������))", 0.95));
			DBProbability.insert(pair<string, double>("���������� � ��������� ���� � �������", 0.98));
			DBProbability.insert(pair<string, double>("�� (������������ ������� �����������)", 0.98));
			DBProbability.insert(pair<string, double>("�� (������� �� �������� ������������ ���������)", 0.98));
			DBProbability.insert(pair<string, double>("��� (������� �� �������� ������������ �� ���������)", 0.85));
			DBProbability.insert(pair<string, double>("��� (��� �������� �� ����� �����)", 0.98));
			DBProbability.insert(pair<string, double>("�� (���� �������� �� ����� �����)", 0.98));
			DBProbability.insert(pair<string, double>("�� �������� (���������� ���� �� �������� �� ����� �����)", 0.98));
			DBProbability.insert(pair<string, double>("��� (������������ ������� �� �����������)", 0.98));
			DBProbability.insert(pair<string, double>("���������� Award BIOS", 0.91));
			DBProbability.insert(pair<string, double>("��������� ���� ������ 3 ������� �������", 0.98));
			DBProbability.insert(pair<string, double>("��������� ���� ������ 1 ������� � 1 �������� ������", 0.98));
			DBProbability.insert(pair<string, double>("���������� Ami BIOS", 0.98));
			DBProbability.insert(pair<string, double>("��������� ���� ������ 4 �������� �������", 0.94));
			DBProbability.insert(pair<string, double>("��������� ���� ������ 5 �������� �������", 0.98));
			DBProbability.insert(pair<string, double>("��������� ���� ������ 7 �������� �������", 0.98));
			DBProbability.insert(pair<string, double>("�� ���������� ��������� ���� � �� ���������� �������", 0.98));
			DBProbability.insert(pair<string, double>("�� (���� �������������)", 0.97));
			DBProbability.insert(pair<string, double>("��� (������� ������ �� �������)", 0.98));
			DBProbability.insert(pair<string, double>("��, �� �� ����� ��������� �� ��� (������� ������ �������, �� �� ����� ���������)", 0.98));
			DBProbability.insert(pair<string, double>("�� (������� ������ �������)", 0.92));
			DBProbability.insert(pair<string, double>("�� (���� ������� �������� ������� ���������)", 0.98));
			DBProbability.insert(pair<string, double>("��� (���� ������� �������� ������� �� ���������)", 0.98));
			DBProbability.insert(pair<string, double>("��� (��� �������������)", 0.98));

			//������������������: ������ ������� ����� � ������ ������, � ����� ������ ������ ����������� ������ ���� � ����������� �� �������, multimap
			DBResult.insert(pair<string, double>("�������� ������� ������.", 0.99));
			DBResult.insert(pair<string, double>("��������� ��������� �������������.", 0.99));
			DBResult.insert(pair<string, double>("������������� ��������� ������� � ��������� ������ (������ ����� ����� (��������)).", 0.01));
			DBResult.insert(pair<string, double>("�������� ������� ������ (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ���� ������� (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ����� ����� (����� ����� ����� � ��������� ������).", 0.99));
			DBResult.insert(pair<string, double>("�������� ����� ����� (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ����������� ����� (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ������� (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ����������� ������ (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ����� (����� ����� ����� � ��������� ������).", 0.99));
			DBResult.insert(pair<string, double>("�������� ����� (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ������� ������ (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ����������� ��������� (������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("�������� ���� ������� (� ��������).", 0.99));
			DBResult.insert(pair<string, double>("�������� ���� ������� (� ���������� �����).", 0.99));
			DBResult.insert(pair<string, double>("���������� ���������� ����������  (������� ����������� ����� � ��������� ����� ��� ������ ����� ����������� �����, ������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("���������� ��������� ������ (������� ����������� ����� � ��������� ����� ��� ������ ����� ����������� �����, ������ ����� ����� (��������)).", 0.99));
			DBResult.insert(pair<string, double>("������������ ��������� ��������. ������ �� � ������.", 0.80));
			DBResult.insert(pair<string, double>("���������� ���� ������� (� ��������).", 0.99));
			DBResult.insert(pair<string, double>("���������� ���� ������� � ���������� �����.", 0.99));
			DBResult.insert(pair<string, double>("���������� ����� � ��������� ����� ���������.", 0.99));

			//----------
			
			init();               
                
			//---------------------------
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label1;





	private:
		
		static int FLAG = 0;
		
		void makeProb(const string& res){
			map<string, double>::iterator j = DBProbability.find(res);
			double minProb = j->second;
			if(minProb < Probability)
				Probability = minProb;
		}
		
		void init(){
			FLAG = 0;
			localQ.clear();

			localResult = "";
			Result = "?";
			firstQuestion = "";
			Probability = 1.0;
			firstQuestion = "���������� �� ��������� ���� � �������?";
			richTextBox1->Text = gcnew String(firstQuestion.c_str());
			
			pair<multimap<string, string>::iterator, multimap<string, string>::iterator> it;
			string question = firstQuestion;
			int q = 1;
			it = DBKnowledge.equal_range(question);
			richTextBox1->Text += "\n";
			for(multimap<string, string>::iterator it2 = it.first; it2 != it.second; ++it2){
				localQ.insert(make_pair(q,it2->second));
				richTextBox1->Text += "\n";
				richTextBox1->Text += gcnew String(Convert::ToString(q));
				richTextBox1->Text += ") ";
				richTextBox1->Text += gcnew String((it2->second).c_str());
				++q;
			}
		}

		void rule(){
            MessageBox::Show("���������� ���������!");
			multimap<string, string>::iterator it;
            it = DBRules.find(localResult);
            if(it == DBRules.end())
				return;
			//Result = it->second;
            
			pair<multimap<string, string>::iterator, multimap<string, string>::iterator> it0;
			it0 = DBRules.equal_range(localResult);
			for(multimap<string, string>::iterator it2 = it0.first; it2 != it0.second; ++it2){
				Result = it2->second;
				richTextBox1->Text += "\n��������� = ";
				richTextBox1->Text += gcnew String(Result.c_str());
				richTextBox1->Text += "\n\n����������:\n";
				richTextBox1->Text += gcnew String(localResult.c_str());
				richTextBox1->Text += " = ";
				richTextBox1->Text += gcnew String(Result.c_str());

				map<string, double>::iterator j = DBResult.find(Result);
				double minProb = j->second;
				if(minProb < Probability)
					Probability = minProb;
				richTextBox1->Text += "\n\n����������� ������������� = ";
				richTextBox1->Text += gcnew String(Convert::ToString(Probability));
				richTextBox1->Text += "\n\n-----------------------------------------------";
				richTextBox1->Text += "\n";
			}
        }


		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
		this->panel1 = (gcnew System::Windows::Forms::Panel());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
		this->textBox1 = (gcnew System::Windows::Forms::TextBox());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->panel1->SuspendLayout();
		this->SuspendLayout();
		// 
		// panel1
		// 
		this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
		this->panel1->Controls->Add(this->button2);
		this->panel1->Controls->Add(this->richTextBox1);
		this->panel1->Controls->Add(this->textBox1);
		this->panel1->Controls->Add(this->label2);
		this->panel1->Controls->Add(this->label1);
		this->panel1->Location = System::Drawing::Point(6, 12);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(636, 550);
		this->panel1->TabIndex = 0;
		// 
		// button2
		// 
		this->button2->Location = System::Drawing::Point(537, 501);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(84, 23);
		this->button2->TabIndex = 4;
		this->button2->Text = L"����������";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
		// 
		// richTextBox1
		// 
		this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(204)));
		this->richTextBox1->Location = System::Drawing::Point(10, 30);
		this->richTextBox1->Name = L"richTextBox1";
		this->richTextBox1->ReadOnly = true;
		this->richTextBox1->Size = System::Drawing::Size(611, 413);
		this->richTextBox1->TabIndex = 3;
		this->richTextBox1->Text = L"";
		// 
		// textBox1
		// 
		this->textBox1->Location = System::Drawing::Point(10, 503);
		this->textBox1->Name = L"textBox1";
		this->textBox1->Size = System::Drawing::Size(426, 20);
		this->textBox1->TabIndex = 2;
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(11, 473);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(40, 13);
		this->label2->TabIndex = 1;
		this->label2->Text = L"�����:";
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(11, 10);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(47, 13);
		this->label1->TabIndex = 0;
		this->label1->Text = L"������:";
		// 
		// button1
		// 
		this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->button1->Location = System::Drawing::Point(549, 574);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(79, 32);
		this->button1->TabIndex = 1;
		this->button1->Text = L"�����";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
		// 
		// Form1
		// 
		this->AcceptButton = this->button2;
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->CancelButton = this->button1;
		this->ClientSize = System::Drawing::Size(656, 616);
		this->Controls->Add(this->button1);
		this->Controls->Add(this->panel1);
		this->DoubleBuffered = true;
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
		this->HelpButton = true;
		this->MaximizeBox = false;
		this->Name = L"Form1";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"���������� ������� ����������� ���������� ����� ��";
		this->panel1->ResumeLayout(false);
		this->panel1->PerformLayout();
		this->ResumeLayout(false);

			}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
			 }
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 //------------------------------------
				 if(FLAG == 1){
					 textBox1->Text = "";
					 init();
					 return;
				 }
				 //-----------------------

				 Y = 0;
				 try{
					 Y = System::Convert::ToInt64( textBox1->Text );
				 }
				 catch(...){
					 textBox1->Text = "";
					 return;
				 }
				 textBox1->Text = "";
				 if(Y <= 0)
					 return;
				 if(Y > localQ.size())
					 return;

				 richTextBox1->Text = "";
			
				string question = "";
                int answer = Y;
                string res = "";
				res = localQ.find(answer)->second;
				
				makeProb(res);
                
				multimap<string, string>::iterator i = DBKnowledge.find(res);
                localResult += res;
				if(i == DBKnowledge.end()){
					FLAG = 1;   
					rule();
					return;
				}
                else
					localResult += " + ";
                question = i->second;
				localQ.clear();

				richTextBox1->Text = gcnew String(question.c_str());

				pair<multimap<string, string>::iterator, multimap<string, string>::iterator> it;
				int q = 1;
				it = DBKnowledge.equal_range(question);
				richTextBox1->Text += "\n";
				for(multimap<string, string>::iterator it2 = it.first; it2 != it.second; ++it2){
					   localQ.insert(make_pair(q,it2->second));
                       richTextBox1->Text += "\n";
			           richTextBox1->Text += gcnew String(Convert::ToString(q));
			           richTextBox1->Text += ") ";
			           richTextBox1->Text += gcnew String((it2->second).c_str());
                       ++q;
				}

			 }
};
}

