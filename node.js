const fs = require('fs');

function processData(filename, writeinto) {
  const rawData = fs.readFileSync(filename, 'utf8');
  const jsonData = JSON.parse(rawData);
  
  fs.writeFileSync(writeinto, JSON.stringify(jsonData.array));
  console.log("added items");

}

const f=require('fs').promises;


async function deleteFile(file) {
  try {
    await f.access(file);
    await f.unlink(file);
    console.log('File deleted successfully');
    } catch (err) {
    if (err.code === 'ENOENT') {
      console.log('File does not exist');
    } else {
      console.error('Error deleting file:', err);
    }
  }
}


processData("nexport.json", "n.txt");
processData("dexport.json", "d.txt");
deleteFile('nexport.json');
deleteFile('dexport.json');