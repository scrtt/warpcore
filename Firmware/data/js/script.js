'use strict'

let baseurl = window.location.origin+window.location.pathname
let state = "on"
let animation = "warpcore"
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

    $("#wpAniButton").click(function(){
        if(animation != "warpcore"){
            animation = "warpcore"
            updateLamp()
        }
    })

    $("#vsAniButton").click(function(){
        if(animation != "versammlung"){
            animation = "versammlung"
            updateLamp()
        }
    })

    $("#rbAniButton").click(function(){
        if(animation != "rainbow"){
            animation = "rainbow"
            updateLamp()
        }
    })

}); 

function updateLamp()
{
    $.get(baseurl+"control/?state="+state+"&animation="+animation, function(data){
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
    switchUiAnimation(data.animation)
}

function disableButton(button){
    $(button).removeClass("button").addClass("lcars-gray-bg");
}

function enableButton(button){
    $(button).removeClass("lcars-gray-bg").addClass("button");
}

function highlightButton(button){
    $(button).removeClass("button").addClass("lcars-hopbush-bg");
}

function normailzeButton(button){
    $(button).removeClass("lcars-hopbush-bg").addClass("button");
}

function switchUiAnimation(uianimation){
    if(uianimation == "warpcore"){
        highlightButton("#wpAniButton")
        normailzeButton("#vsAniButton")
        normailzeButton("#rbAniButton")
    }
    if(uianimation == "versammlung"){
        highlightButton("#vsAniButton")
        normailzeButton("#wpAniButton")
        normailzeButton("#rbAniButton")
    }
    if(uianimation == "rainbow"){
        highlightButton("#rbAniButton")
        normailzeButton("#wpAniButton")
        normailzeButton("#vsAniButton")
    }
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
