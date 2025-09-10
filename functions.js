console.log("file_problem loaded");

let names=localStorage.getItem('names.json');
let dates=localStorage.getItem('dates.json');

let data={names:[], dates:[]};
  
data.names=JSON.parse(names);
data.dates=JSON.parse(dates);

if(!data.names)
  data.names=[];
if(!data.dates)
  data.dates=[];

let x=return_array(data.names, "c1");
let y=return_array(data.dates, "c2");

let food={name: x, date: y};


function gotofrigider(){
    window.location="frigider.html";}

function gotohome(){
    window.location="ananasite.html";}

function display(list, place){
  document.getElementById(place).innerHTML =list;
}

function add_input_box(){
  let input='<form id="fml">';
  input+='<label for="fname">Nume aliment: </label>';
  input+='<input type="text" id="fname"><br><br>';

  input+='<label for="fdate">Data de expirare: </label>';
  input+='<input type="date" id="fdate"><br><br></form>';
  display(input, "demo");

  let button='<button class="done_button" onclick="add(food)">done</button>';
  display(button, "button");
}

function ananas(obj){
  let new_name=f('names.json', "ananas", "c1");
  let new_date=f('dates.json', "niciodata", "c2");
  obj.name=new_name;
  obj.date=new_date;
}

function show_checklist(array){
  let list='';
  let button='<button class="done_button" onclick="remove(food)">done</button>';
  for (let i=0; i<array.name.length; i++){
    list += '<div><input type="checkbox" data-index="'+i+'">'+array.name[i]+'</div>';}
  display(button, "button");
  display(list, "c1");
}

function remove(obj){
  display('', "button");
  const checkboxes = document.querySelectorAll('input[type="checkbox"]:checked');
  let check=[];
  let i;
  for(i=0; i<obj.name.length; i++)
    check.push(0);
  
  for (i=0; i<checkboxes.length; i++)
    check[checkboxes[i].dataset.index]++;
  let len=obj.name.length;

  for(i=0; i<len; i++){
    if(check[i]){
      obj.name.splice(i, 1);
      obj.date.splice(i, 1);
      check.splice(i, 1);
      len--;
      i--;
    }
  }

  localStorage.setItem('names.json', '')
  localStorage.setItem('dates.json', '')
  console.log(obj.date);

  for(let i=0; i<obj.name.length; i++){
    f('names.json', obj.name[i], "c1");
    f('dates.json', obj.date[i], "c2");}
  
  document.getElementById("demo").innerHTML= '';
  document.getElementById("button").innerHTML='';
}

function add(obj){
  name_input=document.getElementById("fname").value;
  date_input=document.getElementById("fdate").value;

  let new_name=f('names.json', name_input, "c1");
  let new_date=f('dates.json', date_input, "c2");
  
  obj.name=new_name;
  obj.date=new_date;

  document.getElementById("demo").innerHTML= '';
  document.getElementById("button").innerHTML='';
}

class alimente {
  constructor(name, date) {
      this.name = name;
      this.date = date;
  }
}

function date(x){
  let s=x.split("-");
  return s[1]-2;
}

function exp(x){
  if(x!="niciodata"){
    const s=x.split("-");
    let d=new Date;
    let ey=Number(s[0]);
    let cy=Number(d.getFullYear());
    let emo=Number(s[1]);
    let cmo=Number(d.getMonth())+1;
    let eday=Number(s[2]); 
    let cday=Number(d.getDate())+1;
    let etotal=0; 
    let ctotal=0;

    if(ey>cy){
      for(var i=1; i<=(ey-cy); i++){
        etotal+=ylen(cy+i-1);
      }
    }
    //adding the months' days starting from the beginning of the current year
    if(emo>cmo){
      for(var i=1; i<=(emo-cmo); i++){
        etotal+=molen(cmo+i-1, ey);
      }
    }

    //adding the days left in the date
    etotal+=eday;
    ctotal+=cday;
    //console.log(d.getDate());

    return etotal-ctotal;
  }
  else
    return "niciodata";
}

function molen(x, year){
  if(year%4==0 && x=="02")
    return 29;
  else{
      switch(x){
    case 1:
      return 31;
    case 2:
      return 28;
    case 3:
      return 31;
    case 4:
      return 30;
    case 5:
      return 31;
    case 6:
      return 30;
    case 7:
      return 31;
    case 8:
      return 31;
    case 9:
      return 30;
    case 10:
      return 31;
    case 11:
      return 30;
    case 12:
      return 31;
    }
  }
}

function ylen(y){
  if(y%4==0)
    return 366;
  else
    return 365;
}

function f(filename, newContent, place) {

  let existingData=localStorage.getItem(filename);
  let jsonData={array:[]};

  if(existingData)
    jsonData.array=JSON.parse(existingData);

  if (!jsonData.array) {
    jsonData.array=[];
  }
   
  if(newContent!=null|| newContent){
    jsonData.array.push(newContent);}

  let y=jsonData.array;
  let z=return_array(y, place);
  let x=JSON.stringify(z);
  let a=make(x);
  let ca=make(x);
  let ex_text='exp de ';
  
  for(let i=0; i<a.length; i++){
    if(place=='c2'){
      let exp_date=String(exp(ca[i]));
      if(exp(ca[i])<0){
        ca[i]=ex_text.concat(exp_date);}
      else
        ca[i]=String(exp(ca[i]));
      }
    }

  safe_display(ca, place, 100);

  localStorage.setItem(filename, JSON.stringify(jsonData.array, 2, null));
  return a;
}

function showStorage() {
    const data = localStorage.getItem('names.json');
    console.log("names data:", data);
}

function safe_display(array, place, chunkSize) {
  const container = document.getElementById(place);
  if (!container) return;

  const listItems = {};
  container.innerHTML = '';

  for (let i=0; i <array.length; i+=chunkSize) {
    const chunk=array.slice(i, i + chunkSize);
    const ul=document.createElement('ul');
    for (let j=0; j<chunk.length; j++) {
      const globalIndex= i+j;
      const li = document.createElement('li');
      if(chunk[j]!=''){
        li.textContent = chunk[j];
        li.dataset.index = globalIndex;
        ul.appendChild(li);
        listItems[globalIndex] = li;}
    }
    container.appendChild(ul);
  }
  return {
    getItem: (index) =>{
      return listItems[index]||null;
    }
  }
}

function return_array(array, place){
  let mi=safe_display(array, place, 100);
  let x={array: []};
  for(let i=0; i<array.length; i++){
      x.array.push(mi.getItem(i).textContent);
  }
  return x.array;
}

function make(array){
  let n=array.slice(2, array.length-2);
  n=n.split('","');
  return n;
}

function exportLocalStorage(filename, place) {
  const data = localStorage.getItem(filename) || '{"array":[]}';
  
  const blob = new Blob([data], { type: 'text/plain' });
  const url = URL.createObjectURL(blob);
  
  const a = document.createElement('a');
  a.href = url;
  a.download = place;
  a.click();
  URL.revokeObjectURL(url);
}
