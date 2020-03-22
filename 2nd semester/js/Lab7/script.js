var f_1 = function(){
	Module.createNamespace("ui.lang.ru", 1.0);
	Module.createNamespace("ui.lang.eng", 1.0);
	Module.require("ui.lang.ru", 1.0);
	Module.require("ui.lang.eng", 1.0);
	Module.createNamespace("about",1.0);
	Module.require("about",1.0);
	about.info = "This program is made as a 7'th laboratory work";
	ui.lang.objects = ["days_left","amount","sw","sesstart","dow","dam","imp","data","cel","your","zad","first","cnt"]
	ui.lang.ru.strings = { 
	"dow":"День недели",
	"dam":"День, месяц и год",
	"DOW":["Воскресенье","Понедельник","Вторник","Среда","Четверг","Пятница","Суббота"],
	"Mon":["Января ","Февраля ","Марта ","Апреля ","Мая ","Июня ","Июля ","Августа ","Сентября ","Октября ","Ноября ","Декабря "],
	"days_left":"До начала сессии <span id='sessbef'></span> дней",
	"sesstart":"Сессия начинается 16 июня",
	"amount":"Сумма заданного количества членов числовой последовательности: <input type='text' disabled='' id='sum'/>",
	"imp":"ВАЖНАЯ ДАТА",
	"data":"Дней прошло : <input id='amount_of_days'/>",
	"cel":"Последовательность: 1+(-2)^n",
	"your":"Ваша последовательность: <input type='text' disabled='' id='sequence'/>",
	"zad":"Считать",
	"first":"Введите значение первого члена n <input type='text' id='n'/>",
	"enter":"Введите памятную для вас дату (ДД.ММ.ГГГГ): ",
	"about":"С чем это связано?",
	"cnt":"Введите кол-во слагаемых k <input type='text' id='k'/>",
	"toSearch":"Введите текст для поиска",
	"err":"Значения введены некорректно!",
	"ad":"ГГГГ.ММ.ДД",
	"sw":"сменить язык",
	"prompt":"Введите номер первого члена и кол-во слагаемых последовательности (через пробел): "}
	ui.lang.eng.strings = { 
	"dow":"Day of the week",
	"dam":"Day, month and year",
	"DOW":["Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"],
	"Mon":["January ","February ","March ","April ","May ","June ","Jule ","August ","September ","October ","November ","December "],
	"days_left":"Days left <span id='sessbef'></span> days",
	"sesstart":"The session begins on June 16",
	"amount":"The sum of a given number of members of a number sequence: <input type='text' disabled='' id='sum'/>",
	"imp":"IMPORTANT DATE",
	"data":"Days passed : <input id='amount_of_days'/> ",
	"cel":"Sequence: 1+(-2)^n",
	"your":"Your sequence: <input type='text' disabled='' id='sequence'/>",
	"zad":"Count",
	"enter":"Enter a memorable date for you (DD.MM.YYYY): ",
	"about":"What is the reason for this?",
	"toSearch":"enter text to search",
	"first":"Set the initial value of n <input type='text' id='n'/>",
	"cnt":"Set the count k of sequence numbers <input type='text' id='k'/>",
	"err":"Values entered incorrectly!",
	"ad":"YYYY.MM.DD",
	"sw":"switch language",
	"prompt":"Enter position of first member and count of members (divide them by spacebar)"}
	ui.lang.switchLanguage = function(l){
		switch(l){
			case "eng":ui.lang.strings = ui.lang.eng.strings; ui.lang.current = "eng";break;
			case "ru":ui.lang.strings = ui.lang.ru.strings; ui.lang.current = "ru";break;
			default:ui.lang.strings = ui.lang.eng.strings; ui.lang.current = "eng";break;
			}
		ui.lang.initLanguage();
		}
	ui.lang.initLanguage = function(){
		var now = new Date();
		ui.lang.objects.forEach(function(el){
			switch(document.getElementById(el).localName){
			case "button":document.getElementById(el).innerHTML = ui.lang.strings[el];break;
			case "tr":document.getElementById(el).innerHTML = ui.lang.strings[el];break;
			case "p":document.getElementById(el).innerHTML = ui.lang.strings[el];break;
			case "b":document.getElementById(el).innerHTML = ui.lang.strings[el];break;
			default:document.getElementById(el).value = ui.lang.strings[el];break;}
		})
		week.innerHTML=ui.lang.strings["DOW"][new Date().getDay()];
		day_month_year.innerHTML= now.getDate() + '  ' + ui.lang.strings["Mon"][now.getMonth()] + date.getFullYear();
		sessbef.innerHTML = Math.floor((new Date(2019,5,16) - new Date()) / 86400000)
		toSearch.placeholder = ui.lang.strings["toSearch"]
	}
	ui.lang.switchLanguage("ru");
	alert("Модуль администрирования модулей загружен!");
	//функция print затрёт то, что было загружено
}
Module.registerInitializationFunction(f_1);
var date = new Date();

function important_date_func() {
//    document.getElementById("important_date").innerHTML = "";
//    document.getElementById("amount_of_days").innerHTML = "";

    var impday = prompt(ui.lang.strings["enter"]);
//    document.getElementById("important_date").value = impday;

    var date_array = impday.split(".");
    var memorable_date = new Date(Number(date_array[2]),Number(date_array[1]-1),Number(date_array[0]));

    document.getElementById("amount_of_days").value = Math.floor((date - memorable_date) / 86400000);
}
function members_of_the_sequence() {
//    document.getElementById("sequence").innerHTML = "";
//    document.getElementById("sum").innerHTML = "";

    var n = document.getElementById("n").value;
    var quantity = document.getElementById("k").value;
    var sum = 0;
    var element;

    function isInteger(num) {
        return num - (Math.floor(num)) === 0 && num > 0;
    }

    if (isInteger(n) && isInteger(quantity)){
        for (var i=0; i<quantity; i++) {
            element = 1 + Math.pow(-2,n);
            document.getElementById("sequence").value = document.getElementById("sequence").value + String(element) + " ";
            sum = sum + element;
            n++;
        }
        document.getElementById("sum").value = sum;
    }
    else {
        alert(ui.lang.strings["err"]);
    }
}

function searchFunc(){
	let str = toSearch.value;  
	let resstr = str.match( /Абдуллаев/i );
    found.innerHTML="<span class='highlight'>"+resstr[0]+"</span>";
}