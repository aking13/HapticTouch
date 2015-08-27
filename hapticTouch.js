var webSocket = require('ws'), ws = new webSocket('ws://127.0.0.1:6437'), five = require('johnny-five'), board = new five.Board(), led, frame;

board.on('ready', function() 

{
	rled = new five.Led(4);
	ws.on('message', function(data, flags) {
		frame = JSON.parse(data);          
	    	if (frame.pointables && frame.pointables.length > 0) {               
			if (frame.pointables[1] && frame.pointables[1].touchDistance <= -0.1) {
				console.log(frame.pointables[1]);                 
				rled.on();             
			} else {
				rled.off();        
			}
		} else {             
			rled.off();        
		}    
	});
});