let baseurl = window.location.origin+window.location.pathname
let state = "on"
$(document).ready(function(){ 
  
    $("#onButton").click(function(){
        state = "on"
        updateLamp()
    })

    $("#offButton").click(function(){
        state = "off"
        updateLamp()
    })
}); 

function updateLamp()
{
    $.get(baseurl+"control/?state="+state);
}