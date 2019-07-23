function change(){
		alert("Hello World!");
}
var value1 = "0";
var op =""; 
var value2 = "";
var memoryValue = "0";
var countDotV1 = 0;
var countDotV2 = 0;
var countNegV1 = 0;
var countNegV2 = 0;
    function display(i){
            if(isNumButton(i) == true){              
                if(op === ""){
                    if(value1 ==='0'){
                        value1 = i;
                     }
                    else{
                        value1 += i;
                    }
                } else {
                        if(value2 === "" || value2 === '0'){
                            value2 = i;
                        }
                        else{
                            value2 += i;
                        }
                }
            } else if(i === '.'){
					var pt ="\\.";
                    if(op !== ("")){
                        countDotV2++;
                        if(countDotV2 === 1){
                            if(value2.search(pt) === -1){
                                value2 += i;
                            } else if(value2 === ""){
                                value2 += "0" + i;
                            }
                        }
                        
                    } else{
                        countDotV1++;
                        if(countDotV1 === 1){
                            if(value1.search(pt) === -1){
                                value1 += i;
                            } else if(value1 === ""){
                                value2 += "0" + i;
                            }
                        }
                       
                    }
            } else if (i === 'neg') {
                if (value1 !== "0") {
    
                    if (op !== "") {
                        if (value2 !== "0") {
                            if (countNegV2 === 0) {
                                value2 = "-" + value2;
                                countNegV2 = 1;
                            } else {
                                value2 = value2.substring(1);
                                countNegV2 = 0;
                            }
                        }
                    } else {
                        if (parseFloat(value1) >= 0) {
                            
                            if (countNegV1 === 0) {
                                value1 = "-" + value1;
                                countNegV1 = 1;
                            } else {
                                value1 = value1.substring(1);
                                countNegV1 = 0;
                            }
                        } else {
                            value1 = value1.substring(1);
                            countNegV1 = 0;
                        }
                    }
                }
            } else if(i === '='){
                var te;
                if(op !== "" && value2 !== ""){
                  var te = 0.0;
                  switch(op){
                      case '+':{
                          te = parseFloat(value1) + parseFloat(value2);
                          break;
                      }
                      case '-':{
                        te = parseFloat(value1) - parseFloat(value2);
                          break;
                      }
                      case '*':{
                        te = parseFloat(value1) * parseFloat(value2);
                          break;
                      }
                      case '/':{
                        te = parseFloat(value1) / parseFloat(value2);
                          break;
                      }
                  }
                  
                  value1 = te.toString();
                  op = value2 = "";
                }
                else {
                   	    op = value2 = "";
                }

            } else if(i === '1/'){
                    if (op !== "") {
                        if (value2 == "") {
                            value2 = "1/";
                        } else if (value2 !== "0") {
                            var tmp;
                            tmp = parseFloat(value2);
                            tmp = (1 / tmp);
                            value2 = tmp.toString();
                        }
                    } else if (value1 !== "0") {
                        var tmp;
                        tmp = parseFloat(value1);
                        tmp = (1 / tmp);
                        value1 = tmp.toString();
                        value2 = op = "";
                    }
            } else if(i === '%'){
                    if (op !== "") {
                        if (value2 !== "0") {
                            // value2 += s;
                            var tmp;
                            tmp = parseFloat(value2);
                            tmp = tmp / 100;
                            value2 = tmp.toString();
                        }
                    } else {
                        if (value1 !== "0") {
                            // value1 += s;
                            var tmp;
                            tmp = parseFloat(value1);
                            tmp = tmp / 100;
                            value1 = tmp.toString();
                        }
                        op = value2 = "";
                    }
                   
            } else if(i === 'sqrt'){
                if (op !== "") {
                    if (value2 !== "") {
                        var kq = parseFloat(value2);
    
                        if (kq > 0) {
                            var result = Math.sqrt(kq);
                            value2 = result.toString();
                        }
                    }
                } else {
                    if (value1 !== "0") {
                        var kq = parseFloat(value1);
    
                        if (kq > 0) {
                            var result = Math.sqrt(kq);
                            value1 = result.toString();
                            op = value2 = "";
                        }
                    }
                }
            } else if (i === 'MS') {
                    if(op !== ""){
                        if(value2 !== ""){
                            memoryValue = value2;
                        } else{
                            memoryValue = value1;
                        }
                    } else{
                        if (value1 !== "0") {
                            memoryValue = value1;
                        }
                    }
                    document.getElementById("btnMR").disabled = false;
                    document.getElementById("btnMC").disabled = false;
            } else if (i === 'MR') {
                if (memoryValue !== "0") {
                    if (op !== "") {
                        value2 = memoryValue;
                    } else {
                        value1 = memoryValue;
                    }
                }
    
            } else if (i === 'MC') {
                memoryValue = "0";
                document.getElementById("btnMR").disabled = true;
                $("#btnMC").attr("disabled","true");
                $("#btnMC").css("background-color","red");
                //document.getElementById("btnMC").style.backgroundColor = "red";
            } else if (i === 'M+') {
                if (memoryValue !== "0") {
                    if(op !== ""){
                        if(value2 !== ""){
                            var te = 0;
                            te = parseFloat(value2) + parseFloat(memoryValue);
                            memoryValue = te.toString();
                        } else {
                            var te = 0;
                            te = parseFloat(value1) + parseFloat(memoryValue);
                            memoryValue = te.toString();
                        }
                    } else {
                        var te = 0;
                        te = parseFloat(value1) + parseFloat(memoryValue);
                        memoryValue = te.toString();
                    }
                } else {
                        if(op !== ""){
                            if(value2 !== ""){
                                memoryValue = value2;
                            } else{
                                memoryValue = value1;
                            }
                        } else{
                            if (value1 !== "0") {
                                memoryValue = value1;
                            }
                        }
                }
                document.getElementById("btnMR").disabled = false;
                document.getElementById("btnMC").disabled = false;
            } else if(i === "CE") {
                    if (op !== "") {
                        if (value2 !== "") {
                            value2 = "";
                        }
                    } else {
                        if(value1 !== ""){
                            value1 = "0";
                        }
                    }
            }  else if(i === "B"){
                    if(op !== ""){
                        if(value2 !== "0"){
                            if(parseFloat(value2) < 0){
                                if(value2.length > 2){
                                    value2 = value2.substring(0, value2.length - 1);
                                } else if(value2.length == 2) {
                                    value2 = "0";
                                }
                            } else {
                                if(value2.length > 1){
                                    value2 = value2.substring(0, value2.length - 1);
                                } else if(value2.length == 1) {
                                    value2 = "0";
                                }
                            }
                        }
                    } else {
                        if(value1 !== "0"){
                            if(parseFloat(value1) < 0){
                                if(value1.length > 2){
                                    value1 = value1.substring(0, value1.length - 1);
                                } else if(value1.length == 2) {
                                    value1 = "0";
                                }
                            } else {
                                if(value1.length > 1){
                                    value1 = value1.substring(0, value1.length - 1);
                                } else if(value1.length == 1) {
                                    value1 = "0";
                                }
                            }
                        }   
                    }
            } else {
                if(value1 === "0"){
                    op = value2 = "";
                }
                else{
                    if(op === "" || value2 === ""){
                        op = i;
                    }else{
                        var te = 0.0;
                        if (op === "+") {
                            te = parseFloat(value1) + parseFloat(value2);
                        } else if (op === "-") {
                            te = parseFloat(value1) - parseFloat(value2);
                        } else if (op === "/") {
                            te = parseFloat(value1) / parseFloat(value2);
                        } else if (op === "*") {
                            te = parseFloat(value1) * parseFloat(value2);
                        }
                        value1 = te.toString();
                        op = i;
                        value2 = "";
                    }
                    countDotV1 = 0;
                    countDotV2 = 0;
                    countNegV1 = 0;
                    countNegV2 = 0;
                }
            }          
            document.getElementById("textField").innerHTML = (value1+op+value2);
            document.getElementById("memoryField").innerHTML = memoryValue;
        }

        function clearAll(){
            value1 = "0";
            op = value2 = "";
            countDotV1 = countDotV2 = 0;
            countNegV1 = countNegV2 = 0;
            document.getElementById("textField").innerHTML = (value1+op+value2);
        }

        function isNumButton(i){
            switch(i){
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                case '0':{
                    return true;
                    break;
                }
            }
            return false;
        }

        //xu ly su khien mouse over: thay doi mau background color cua button
        function mouseOverHandle(id){
            var btn = document.getElementById(id);
            btn.style.backgroundColor = "red";
        }

        function mouseOutHandle(id){
            var btn = document.getElementById(id);
            btn.style.backgroundColor = "cadetblue";
        }

        var btnDot = document.getElementById("btnDot");
        btnDot.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnDot.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnCal = document.getElementById("btnCal");
        btnCal.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnCal.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnPlus = document.getElementById("btnPlus");
        btnPlus.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnPlus.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnPercent = document.getElementById("btnPercent");
        btnPercent.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnPercent.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnC = document.getElementById("btnC");
        btnC.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnC.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnMinus = document.getElementById("btnMinus");
        btnMinus.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnMinus.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnPraction = document.getElementById("btnPraction");
        btnPraction.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnPraction.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnCE = document.getElementById("btnCE");
        btnCE.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnCE.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnTimes = document.getElementById("btnTimes");
        btnTimes.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnTimes.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnNeg = document.getElementById("btnNeg");
        btnNeg.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnNeg.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnDivide = document.getElementById("btnDivide");
        btnDivide.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnDivide.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnSqrt = document.getElementById("btnSqrt");
        btnSqrt.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnSqrt.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnBack = document.getElementById("btnBack");
        btnBack.onmouseover = function (event){
            event.target.style.backgroundColor = "yellow";
        };
        btnBack.onmouseout = function (event){
            event.target.style.backgroundColor = "cyan";
        };

        var btnMS = document.getElementById("btnMS");
        btnMS.addEventListener("mouseover",function(event){
            event.target.style.backgroundColor = "green";
        });

        btnMS.addEventListener("mouseout", function(event){
            event.target.style.backgroundColor = "red";
        });

        var btnMR = document.getElementById("btnMR");
        btnMR.addEventListener("mouseover",function(event){
            event.target.style.backgroundColor = "green";
        });

        btnMR.addEventListener("mouseout", function(event){
            event.target.style.backgroundColor = "red";
        });

        var btnMC = document.getElementById("btnMC");
        btnMC.addEventListener("mouseover",function(event){
            event.target.style.backgroundColor = "green";
        });

        btnMC.addEventListener("mouseout", function(event){
            event.target.style.backgroundColor = "red";
        });

        var btnMP = document.getElementById("btnMP");
        btnMP.addEventListener("mouseover",function(event){
            event.target.style.backgroundColor = "green";
        });

        btnMP.addEventListener("mouseout", function(event){
            event.target.style.backgroundColor = "red";
        });

