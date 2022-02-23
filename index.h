const char webpage[] PROGMEM = R"=====(
<html>
<head>
  <script>
    var Socket;
    function init() {
      Socket = new WebSocket('ws://' + window.location.hostname + ':81/');
      Socket.onmessage = function(event){
        document.getElementById("rxConsole").value += event.data;
      }
    }
    function sendText(){
      Socket.send(document.getElementById("txBar").value);
      document.getElementById("txBar").value = "";
    }
    function sendBrightness(){
      Socket.send("#"+document.getElementById("relayVal").value);
    }    
  </script>
</head>
<body onload="javascript:init()">
  <head>
<h1 style="text-align: center;"><strong><span style="color: #993300;">IoT</span></strong></h1>
<h2 style="text-align: center;"><span style="color: #993300;"><strong>&nbsp;Room Temperature Controller</strong></span></h2>
</head>
<body onload="javascript:init()">
  <div>
<p style="text-align: center;"><textarea  id="rxConsole" class="mbt-textarea" textarea="" style="width: 590px; height: 190px; border: 1px solid red">  </textarea></p>
</div>
  <hr/>
   <div>
     <p style="text-align: center;"><button type="button" id="relayVal" value="6" style="width: 59px; height: 19px; background-color: #0f400f; border: 2px solid #400813;" onclick= "sendBrightness()">ON</button></p>
<p style="text-align: center;"><button type="button" id="relayVal" value="8" style="width: 59px; height: 19px; background-color: #0f400f; border: 2px solid #400813;" onclick= "sendBrightness()">OFF</button></p>
  </div>   
</body>
<body style="background-color: #061A05;">
</body>
</html>
)====="; 
