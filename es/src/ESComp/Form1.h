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
                               ("Включается только Монитор + Да (Шнур питания подключен (к Системному блоку)) + Да (Шнур питания поврежден (к Системному блоку))",
                                "Заменить шнур питания (к Системному блоку)."));

            DBRules.insert(pair<string, string>
                               ("Включается только Монитор + Да (Шнур питания подключен (к Системному блоку)) + Нет (Шнур питания не поврежден (к Системному блоку)) + Да (Платы в Системном блоке установлены правильно) + Да (Есть следы сгорания какой либо платы в Системном блоке) + Да (Есть гарантия на сгоревшую плату в Системном блоке)",
                                "Заменить плату (Взять новую плату в Сервисном центре)."));

            DBRules.insert(pair<string, string>
                               ("Включается только Монитор + Да (Шнур питания подключен (к Системному блоку)) + Нет (Шнур питания не поврежден (к Системному блоку)) + Да (Платы в Системном блоке установлены правильно) + Да (Есть следы сгорания какой либо платы в Системном блоке) + Нет (Нет гарантии на сгоревшую плату в Системном блоке)",
                                "Заменить плату (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается только Монитор + Да (Шнур питания подключен (к Системному блоку)) + Нет (Шнур питания не поврежден (к Системному блоку)) + Да (Платы в Системном блоке установлены правильно) + Нет (Нет следов сгорания какой либо платы в Системном блоке)",
                                "Заменить блок питания (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается только Монитор + Да (Шнур питания подключен (к Системному блоку)) + Нет (Шнур питания не поврежден (к Системному блоку)) + Нет (Платы в Системном блоке установлены не правильно)",
                                "Установить платы в Системном блоке правильно."));

            DBRules.insert(pair<string, string>
                               ("Включается только Монитор + Нет (Шнур питания не подключен (к Системному блоку))",
                                "Подключить шнур питания к Системному блоку."));

            DBRules.insert(pair<string, string>
                               ("Включается только Системный блок + Да (Шнур питания подключен (к Монитору)) + Да (Шнур питания поврежден (к Монитору))",
                                "Заменить шнур питания (к Монитору)."));

            DBRules.insert(pair<string, string>
                               ("Включается только Системный блок + Да (Шнур питания подключен (к Монитору)) + Нет (Шнур питания не поврежден (к Монитору))",
                                "Заменить Монитор (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается только Системный блок + Нет (Шнур питания не подключен (к Монитору))",
                                "Подключить шнур питания (к Монитору)."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Да (Операционная система загружается) + Да (символы на Мониторе отображаются нормально)",
                                "Персональный компьютер работает. Ошибка не в железе."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Да (Операционная система загружается) + Нет (символы на Мониторе отображаются не нормально) + Нет (Нет гарантии на Видео карту)",
                                "Заменить Видео карту (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Да (Операционная система загружается) + Нет (символы на Мониторе отображаются не нормально) + Да (Есть гарантия на Видео карту)",
                                "Заменить Видео карту (Взять новую плату в Сервисном центре)."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Да (Операционная система загружается) + Нет (символы на Мониторе отображаются не нормально) + Не известно (Неизвестно есть ли гарантия на Видео карту)",
                                "Заменить Видео карту (Купить новую плату (запчасть))."));
			DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Да (Операционная система загружается) + Нет (символы на Мониторе отображаются не нормально) + Не известно (Неизвестно есть ли гарантия на Видео карту)",
                                "Дополнительно проверить Монитор в Сервисном центре (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Нет (Операционная система не загружается) + Установлен Award BIOS + Системный блок издает 3 длинных сигнала",
                                "Неисправен Контроллер клавиатуры  (Отнести Материнскую плату в Сервисный центр или купить новую Материнскую плату, Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Нет (Операционная система не загружается) + Установлен Award BIOS + Системный блок издает 1 длинный и 1 короткий сигнал",
                                "Заменить Оперативную память (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Нет (Операционная система не загружается) + Установлен Ami BIOS + Системный блок издает 4 коротких сигнала",
                                "Неисправен Системный таймер (Отнести Материнскую плату в Сервисный центр или купить новую Материнскую плату, Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Нет (Операционная система не загружается) + Установлен Ami BIOS + Системный блок издает 5 коротких сигнала",
                                "Заменить Центральный процессор (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Включается и Системный блок и Монитор + Нет (Операционная система не загружается) + Установлен Ami BIOS + Системный блок издает 7 коротких сигнала",
                                "Заменить материнскую плату (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Не включается Системный блок и не включается Монитор + Да (Есть электричество) + Нет (Сетевой фильтр не включен)",
                                "Включите сетевой фильтр."));

            DBRules.insert(pair<string, string>
                               ("Не включается Системный блок и не включается Монитор + Да (Есть электричество) + Да, но не горит светодиод на нем (Сетевой фильтр включен, но не горит светодиод)",
                                "Замените Сетевой фильтр (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Не включается Системный блок и не включается Монитор + Да (Есть электричество) + Да (Сетевой фильтр включен) + Да (Шнур питания Сетевого фильтра поврежден)",
                                "Заменить Сетевой фильтр (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Не включается Системный блок и не включается Монитор + Да (Есть электричество) + Да (Сетевой фильтр включен) + Нет (Шнур питания Сетевого фильтра не поврежден)",
                                "Заменить Сетевой фильтр (Купить новую плату (запчасть))."));

            DBRules.insert(pair<string, string>
                               ("Не включается Системный блок и не включается Монитор + Нет (Нет электричества)",
                                "Дождаться включения электричества."));

			DBKnowledge.insert(pair<string, string>("Включается ли Системный блок и Монитор?", "Включается только Монитор"));
			DBKnowledge.insert(pair<string, string>("Включается только Монитор", "Подключен ли шнур питания (к Системному блоку)?"));
			DBKnowledge.insert(pair<string, string>("Подключен ли шнур питания (к Системному блоку)?", "Да (Шнур питания подключен (к Системному блоку))"));
			DBKnowledge.insert(pair<string, string>("Да (Шнур питания подключен (к Системному блоку))", "Поврежден ли шнур питания (к Системному блоку)?"));
			DBKnowledge.insert(pair<string, string>("Поврежден ли шнур питания (к Системному блоку)?", "Да (Шнур питания поврежден (к Системному блоку))"));
			DBKnowledge.insert(pair<string, string>("Поврежден ли шнур питания (к Системному блоку)?", "Нет (Шнур питания не поврежден (к Системному блоку))"));
			DBKnowledge.insert(pair<string, string>("Нет (Шнур питания не поврежден (к Системному блоку))", "Правильно ли установлены платы в Системном блоке?"));
			DBKnowledge.insert(pair<string, string>("Правильно ли установлены платы в Системном блоке?", "Да (Платы в Системном блоке установлены правильно)"));
			DBKnowledge.insert(pair<string, string>("Да (Платы в Системном блоке установлены правильно)", "Есть ли следы сгорания какой либо платы в Системном блоке?"));
			DBKnowledge.insert(pair<string, string>("Есть ли следы сгорания какой либо платы в Системном блоке?", "Да (Есть следы сгорания какой либо платы в Системном блоке)"));
			DBKnowledge.insert(pair<string, string>("Да (Есть следы сгорания какой либо платы в Системном блоке)", "Есть ли гарантия на сгоревшую плату в Системном блоке?"));
			DBKnowledge.insert(pair<string, string>("Есть ли гарантия на сгоревшую плату в Системном блоке?", "Да (Есть гарантия на сгоревшую плату в Системном блоке)"));
			DBKnowledge.insert(pair<string, string>("Есть ли гарантия на сгоревшую плату в Системном блоке?", "Нет (Нет гарантии на сгоревшую плату в Системном блоке)"));
			DBKnowledge.insert(pair<string, string>("Есть ли следы сгорания какой либо платы в Системном блоке?", "Нет (Нет следов сгорания какой либо платы в Системном блоке)"));
			DBKnowledge.insert(pair<string, string>("Правильно ли установлены платы в Системном блоке?", "Нет (Платы в Системном блоке установлены не правильно)"));
			DBKnowledge.insert(pair<string, string>("Подключен ли шнур питания (к Системному блоку)?", "Нет (Шнур питания не подключен (к Системному блоку))"));
			DBKnowledge.insert(pair<string, string>("Включается ли Системный блок и Монитор?", "Включается только Системный блок"));
			DBKnowledge.insert(pair<string, string>("Включается только Системный блок", "Подключен ли шнур питания (к Монитору)?"));
			DBKnowledge.insert(pair<string, string>("Подключен ли шнур питания (к Монитору)?", "Да (Шнур питания подключен (к Монитору))"));
			DBKnowledge.insert(pair<string, string>("Да (Шнур питания подключен (к Монитору))", "Поврежден ли шнур питания(к Монитору)?"));
			DBKnowledge.insert(pair<string, string>("Поврежден ли шнур питания(к Монитору)?", "Да (Шнур питания поврежден (к Монитору))"));
			DBKnowledge.insert(pair<string, string>("Поврежден ли шнур питания(к Монитору)?", "Нет (Шнур питания не поврежден (к Монитору))"));
			DBKnowledge.insert(pair<string, string>("Подключен ли шнур питания (к Монитору)?", "Нет (Шнур питания не подключен (к Монитору))"));
			DBKnowledge.insert(pair<string, string>("Включается ли Системный блок и Монитор?", "Включается и Системный блок и Монитор"));
			DBKnowledge.insert(pair<string, string>("Включается и Системный блок и Монитор", "Загружается ли Операционная система?"));
			DBKnowledge.insert(pair<string, string>("Загружается ли Операционная система?", "Да (Операционная система загружается)"));
			DBKnowledge.insert(pair<string, string>("Да (Операционная система загружается)", "Нормально ли отображаются символы на Мониторе?"));
			DBKnowledge.insert(pair<string, string>("Нормально ли отображаются символы на Мониторе?", "Да (символы на Мониторе отображаются нормально)"));
			DBKnowledge.insert(pair<string, string>("Нормально ли отображаются символы на Мониторе?", "Нет (символы на Мониторе отображаются не нормально)"));
			DBKnowledge.insert(pair<string, string>("Нет (символы на Мониторе отображаются не нормально)", "Есть ли гарантия на Видео карту?"));
			DBKnowledge.insert(pair<string, string>("Есть ли гарантия на Видео карту?", "Нет (Нет гарантии на Видео карту)"));
			DBKnowledge.insert(pair<string, string>("Есть ли гарантия на Видео карту?", "Да (Есть гарантия на Видео карту)"));
			DBKnowledge.insert(pair<string, string>("Есть ли гарантия на Видео карту?", "Не известно (Неизвестно есть ли гарантия на Видео карту)"));
			DBKnowledge.insert(pair<string, string>("Загружается ли Операционная система?", "Нет (Операционная система не загружается)"));
			DBKnowledge.insert(pair<string, string>("Нет (Операционная система не загружается)", "Какой установлен BIOS?"));
			DBKnowledge.insert(pair<string, string>("Какой установлен BIOS?", "Установлен Award BIOS"));
			DBKnowledge.insert(pair<string, string>("Установлен Award BIOS", "Сколько сигналов издает Системный блок Award?"));
			DBKnowledge.insert(pair<string, string>("Сколько сигналов издает Системный блок Award?", "Системный блок издает 3 длинных сигнала"));
			DBKnowledge.insert(pair<string, string>("Сколько сигналов издает Системный блок Award?", "Системный блок издает 1 длинный и 1 короткий сигнал"));
			DBKnowledge.insert(pair<string, string>("Какой установлен BIOS?", "Установлен Ami BIOS"));
			DBKnowledge.insert(pair<string, string>("Установлен Ami BIOS", "Сколько сигналов издает Системный блок Ami?"));
			DBKnowledge.insert(pair<string, string>("Сколько сигналов издает Системный блок Ami?", "Системный блок издает 4 коротких сигнала"));
			DBKnowledge.insert(pair<string, string>("Сколько сигналов издает Системный блок Ami?", "Системный блок издает 5 коротких сигнала"));
			DBKnowledge.insert(pair<string, string>("Сколько сигналов издает Системный блок Ami?", "Системный блок издает 7 коротких сигнала"));
			DBKnowledge.insert(pair<string, string>("Включается ли Системный блок и Монитор?", "Не включается Системный блок и не включается Монитор"));
			DBKnowledge.insert(pair<string, string>("Не включается Системный блок и не включается Монитор", "Есть ли электричество?"));
			DBKnowledge.insert(pair<string, string>("Есть ли электричество?", "Да (Есть электричество)"));
			DBKnowledge.insert(pair<string, string>("Да (Есть электричество)", "Включен ли Сетевой фильтр?"));
			DBKnowledge.insert(pair<string, string>("Включен ли Сетевой фильтр?", "Нет (Сетевой фильтр не включен)"));
			DBKnowledge.insert(pair<string, string>("Включен ли Сетевой фильтр?", "Да, но не горит светодиод на нем (Сетевой фильтр включен, но не горит светодиод)"));
			DBKnowledge.insert(pair<string, string>("Включен ли Сетевой фильтр?", "Да (Сетевой фильтр включен)"));
			DBKnowledge.insert(pair<string, string>("Да (Сетевой фильтр включен)", "Поврежден ли шнур Сетевого фильтра?"));
			DBKnowledge.insert(pair<string, string>("Поврежден ли шнур Сетевого фильтра?", "Да (Шнур питания Сетевого фильтра поврежден)"));
			DBKnowledge.insert(pair<string, string>("Поврежден ли шнур Сетевого фильтра?", "Нет (Шнур питания Сетевого фильтра не поврежден)"));
			DBKnowledge.insert(pair<string, string>("Есть ли электричество?", "Нет (Нет электричества)"));

			DBProbability.insert(pair<string, double>("Включается только Монитор", 0.98));
			DBProbability.insert(pair<string, double>("Включается только Системный блок", 0.98));
			DBProbability.insert(pair<string, double>("Да (Шнур питания подключен (к Системному блоку))", 0.98));
			DBProbability.insert(pair<string, double>("Да (Шнур питания поврежден (к Системному блоку))", 0.88));
			DBProbability.insert(pair<string, double>("Нет (Шнур питания не поврежден (к Системному блоку))", 0.98));
			DBProbability.insert(pair<string, double>("Да (Платы в Системном блоке установлены правильно)", 0.98));
			DBProbability.insert(pair<string, double>("Да (Есть следы сгорания какой либо платы в Системном блоке)", 0.98));
			DBProbability.insert(pair<string, double>("Да (Есть гарантия на сгоревшую плату в Системном блоке)", 0.92));
			DBProbability.insert(pair<string, double>("Нет (Нет гарантии на сгоревшую плату в Системном блоке)", 0.98));
			DBProbability.insert(pair<string, double>("Нет (Нет следов сгорания какой либо платы в Системном блоке)", 0.98));
			DBProbability.insert(pair<string, double>("Нет (Платы в Системном блоке установлены не правильно)", 0.96));
			DBProbability.insert(pair<string, double>("Нет (Шнур питания не подключен (к Системному блоку))", 0.98));
			DBProbability.insert(pair<string, double>("Да (Шнур питания подключен (к Монитору))", 0.98));
			DBProbability.insert(pair<string, double>("Да (Шнур питания поврежден (к Монитору))", 0.98));
			DBProbability.insert(pair<string, double>("Нет (Шнур питания не поврежден (к Монитору))", 0.98));
			DBProbability.insert(pair<string, double>("Нет (Шнур питания не подключен (к Монитору))", 0.95));
			DBProbability.insert(pair<string, double>("Включается и Системный блок и Монитор", 0.98));
			DBProbability.insert(pair<string, double>("Да (Операционная система загружается)", 0.98));
			DBProbability.insert(pair<string, double>("Да (символы на Мониторе отображаются нормально)", 0.98));
			DBProbability.insert(pair<string, double>("Нет (символы на Мониторе отображаются не нормально)", 0.85));
			DBProbability.insert(pair<string, double>("Нет (Нет гарантии на Видео карту)", 0.98));
			DBProbability.insert(pair<string, double>("Да (Есть гарантия на Видео карту)", 0.98));
			DBProbability.insert(pair<string, double>("Не известно (Неизвестно есть ли гарантия на Видео карту)", 0.98));
			DBProbability.insert(pair<string, double>("Нет (Операционная система не загружается)", 0.98));
			DBProbability.insert(pair<string, double>("Установлен Award BIOS", 0.91));
			DBProbability.insert(pair<string, double>("Системный блок издает 3 длинных сигнала", 0.98));
			DBProbability.insert(pair<string, double>("Системный блок издает 1 длинный и 1 короткий сигнал", 0.98));
			DBProbability.insert(pair<string, double>("Установлен Ami BIOS", 0.98));
			DBProbability.insert(pair<string, double>("Системный блок издает 4 коротких сигнала", 0.94));
			DBProbability.insert(pair<string, double>("Системный блок издает 5 коротких сигнала", 0.98));
			DBProbability.insert(pair<string, double>("Системный блок издает 7 коротких сигнала", 0.98));
			DBProbability.insert(pair<string, double>("Не включается Системный блок и не включается Монитор", 0.98));
			DBProbability.insert(pair<string, double>("Да (Есть электричество)", 0.97));
			DBProbability.insert(pair<string, double>("Нет (Сетевой фильтр не включен)", 0.98));
			DBProbability.insert(pair<string, double>("Да, но не горит светодиод на нем (Сетевой фильтр включен, но не горит светодиод)", 0.98));
			DBProbability.insert(pair<string, double>("Да (Сетевой фильтр включен)", 0.92));
			DBProbability.insert(pair<string, double>("Да (Шнур питания Сетевого фильтра поврежден)", 0.98));
			DBProbability.insert(pair<string, double>("Нет (Шнур питания Сетевого фильтра не поврежден)", 0.98));
			DBProbability.insert(pair<string, double>("Нет (Нет электричества)", 0.98));

			//Усовершенствование: разные цепочки ведут к одному ответу, у этого ответа разная вероятность должна быть в зависимости от цепочки, multimap
			DBResult.insert(pair<string, double>("Включите сетевой фильтр.", 0.99));
			DBResult.insert(pair<string, double>("Дождаться включения электричества.", 0.99));
			DBResult.insert(pair<string, double>("Дополнительно проверить Монитор в Сервисном центре (Купить новую плату (запчасть)).", 0.01));
			DBResult.insert(pair<string, double>("Замените Сетевой фильтр (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить блок питания (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить Видео карту (Взять новую плату в Сервисном центре).", 0.99));
			DBResult.insert(pair<string, double>("Заменить Видео карту (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить материнскую плату (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить Монитор (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить Оперативную память (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить плату (Взять новую плату в Сервисном центре).", 0.99));
			DBResult.insert(pair<string, double>("Заменить плату (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить Сетевой фильтр (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить Центральный процессор (Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Заменить шнур питания (к Монитору).", 0.99));
			DBResult.insert(pair<string, double>("Заменить шнур питания (к Системному блоку).", 0.99));
			DBResult.insert(pair<string, double>("Неисправен Контроллер клавиатуры  (Отнести Материнскую плату в Сервисный центр или купить новую Материнскую плату, Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Неисправен Системный таймер (Отнести Материнскую плату в Сервисный центр или купить новую Материнскую плату, Купить новую плату (запчасть)).", 0.99));
			DBResult.insert(pair<string, double>("Персональный компьютер работает. Ошибка не в железе.", 0.80));
			DBResult.insert(pair<string, double>("Подключить шнур питания (к Монитору).", 0.99));
			DBResult.insert(pair<string, double>("Подключить шнур питания к Системному блоку.", 0.99));
			DBResult.insert(pair<string, double>("Установить платы в Системном блоке правильно.", 0.99));

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
			firstQuestion = "Включается ли Системный блок и Монитор?";
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
            MessageBox::Show("Вычисления завершены!");
			multimap<string, string>::iterator it;
            it = DBRules.find(localResult);
            if(it == DBRules.end())
				return;
			//Result = it->second;
            
			pair<multimap<string, string>::iterator, multimap<string, string>::iterator> it0;
			it0 = DBRules.equal_range(localResult);
			for(multimap<string, string>::iterator it2 = it0.first; it2 != it0.second; ++it2){
				Result = it2->second;
				richTextBox1->Text += "\nРезультат = ";
				richTextBox1->Text += gcnew String(Result.c_str());
				richTextBox1->Text += "\n\nОбъяснение:\n";
				richTextBox1->Text += gcnew String(localResult.c_str());
				richTextBox1->Text += " = ";
				richTextBox1->Text += gcnew String(Result.c_str());

				map<string, double>::iterator j = DBResult.find(Result);
				double minProb = j->second;
				if(minProb < Probability)
					Probability = minProb;
				richTextBox1->Text += "\n\nВероятность достоверности = ";
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
		this->button2->Text = L"Продолжить";
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
		this->label2->Text = L"Ответ:";
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(11, 10);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(47, 13);
		this->label1->TabIndex = 0;
		this->label1->Text = L"Вопрос:";
		// 
		// button1
		// 
		this->button1->DialogResult = System::Windows::Forms::DialogResult::Cancel;
		this->button1->Location = System::Drawing::Point(549, 574);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(79, 32);
		this->button1->TabIndex = 1;
		this->button1->Text = L"Выход";
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
		this->Text = L"Экспертная система диагностики аппаратной части ПК";
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

