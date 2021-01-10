"use strict"

let baseurl = window.location.origin+window.location.pathname
let state = "on"
$(document).ready(function(){ 
    refresh()
    $("#onButton").click(function(){
        if(state != "on"){
            state = "on"
            updateLamp()
        } 
    })

    $("#offButton").click(function(){
        if(state != "off"){
            state = "off"
            updateLamp()
        }
    })

    $("#toggleButton").click(function(){
        if(state != "off"){
            state = "off"
            updateLamp()
        }
        else{
            state = "on"
            updateLamp()
        }
    })
}); 

function updateLamp()
{
    $.get(baseurl+"control/?state="+state, function(data){
        updateUi(data)
    });
}

function refresh()
{
    $.get(baseurl+"control", function(data){
        updateUi(data)
    });
}

function updateUi(data)
{
    switchUiState(data.state)
}

function disableButton(button){
    $(button).removeClass("button").addClass("lcars-gray-bg");
}

function enableButton(button){
    $(button).removeClass("lcars-gray-bg").addClass("button");
}

function switchUiState(uistate){
    if(uistate == "on"){
        disableButton("#onButton")
        enableButton("#offButton")
        state = uistate
    }
    if(uistate == "off"){
        enableButton("#onButton")
        disableButton("#offButton")
        state = uistate
    }
}
