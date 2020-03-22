function task1() {
		var surname=prompt("Введите фамилию:", "");
        var name=prompt("Введите имя:", "");
		var patr=prompt("Введите отчество:", "");
		var agree=confirm("Ваши данные:\n"+"Фамилия:"+surname+"\nИмя:"+name+"\nОтчество:"+patr+"\nПодтвердить данные?");
		if(agree)
		{
			alert("Привет, "+name);
		}
		else
		{
			alert("Ошибка!");
		}
	}
    function task2() {
		var result;
		var hours=parseInt(prompt("Введите часы:", "0"));
		var minutes=parseInt(prompt("Введите минуты:", "0"));
		if (minutes==59 && hours==23) {
            hours = 0;
            minutes = 0;
        }
        else if (minutes<59) {
            minutes++;
        }
        else if (minutes==59) {
            hours++;
            minutes = 0;
        }
        alert("Через минуту будет "+hours+":"+minutes)
	}
	function task3(){
		var str, n = 10, i, j;
		var strDiv = "";
		var div = document.getElementById("task2");
        var greencount = 1
		strDiv+="<table>\n";
		for (i = 0; i < n; i++) {
			strDiv+="<tr>\n";
			for (j = 0; j < greencount; j++) {
				str = "class='green'";
				strDiv+="<td " + str + "></td>";
			}
            for (j = greencount; j<n; j++) {
                str = "class='yellow'";
                strDiv+="<td " + str + "></td>";
            }
            greencount++;
			strDiv+="</tr>\n";
		}
		strDiv+="</table>\n";
		div.innerHTML+=strDiv;
		
	}
	function task4(){
		var div = document.getElementById("task3");
		var strDiv="";
		strDiv+="<table>\n";
		var ylw = 1;
		var n=10;
		for (i = 0; i < n; i++) {
			strDiv+="<tr>";
			for (j = 0; j < n; j++) {
				if(j==ylw){
					str = "class='yellow'";
                    ylw+=3;
				} 
				else {
					str = "class='green'";
				}
                ylw%=10
				strDiv+="<td " + str + "></td>";
			}
			strDiv+="</tr>\n";
		}
		strDiv+="</table>\n";
		div.innerHTML+=strDiv;
	}
	function task5(){
//        var N;
//        N = prompt
        
		var N=prompt("Введите натуральное число:", "0");
//		var Nstr = "" + N;
        len = N.length;
        var a;
        var b;
        var medind;
        var i = len%2;
        if (i!=0) {
            medind = Math.floor(len/2);
            a = N.substring(0, medind);
            b = N.substring(medind + 1).split("").reverse().join("");
        } else {
            medind = len/2;
            a = N.substring(0, medind);
            b = N.substring(medind).split("").reverse().join("");
        }
        if (a == b) {
            alert(N + " является палиндромом");
        } else {
            alert(N + " не является палиндромом");
        }
	}