

onmessage = function(event){get_work()}



function get_work()
{	
    postMessage("In Web Worker");
	
    var g_w = new XMLHttpRequest();
    g_w.open("GET", "http://localhost:3000");
    g_w.send();
    
    
    setTimeout("get_work()", 10);
    
    
}


function get_work2() {
	var counter = 0;
	while (counter < 1000) {
		$.ajax({
			url : 'http://1-dot-tonal-premise-641.appspot.com/count',
			async : true,
			
			
		});
		counter++;
	}
}
