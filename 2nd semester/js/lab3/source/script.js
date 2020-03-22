    var months=["Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"];
    var dayOfWeek=["Воскресенье", "Понедельник", "Вторник", "Среда", "Четверг", "Пятница", "Суббота"];
    var dd = new Date();
    var year=dd.getFullYear();
    var month=months[dd.getMonth()];
    var dow=dayOfWeek[dd.getDay()];
    document.getElementById("date").innerText=dd.getDate() + ", " + month + ", " + year;
    document.getElementById("dow").innerText=dow;
    var sessionDay= new Date(dd.getFullYear(), 5, 18);
    document.getElementById("Session").innerHTML= Math.ceil((sessionDay.getTime()- dd.getTime()) / 86400000);

    function memDate()
    {
        var date=prompt("Введите памятную дату:(дд, мм, гг)");
        date = date.split(".");
        var datass =  new  Date(+date[2], +date[1]-1, +date[0]);
        var previoslyDays = Math.ceil((dd.getTime() - datass.getTime()) / 86400000);
        if (previoslyDays > 365){
            document.getElementById("ago").value=previoslyDays;
        }
        else
        {
            alert("Прошло менее года!");
        }
    }
    function countUp()
    {
        var result=0;
        var k=1;
        var n=1;
        k=+document.getElementById("k").value;
        n=+document.getElementById("n").value;

        console.log(k);
        console.log(n);
        if(k===0 || n===0)
        {
            alert("Введите числа > 0!");
            return 0;
        }

        if(k && n)
        {
            for(var i=1; i<=n; i++)
            {
                result+=1+Math.pow(-2, k);
                k++;
            }
            document.getElementById("result").value=result;
        }
        else
        {
            alert("Введите числа!");
        }
    }