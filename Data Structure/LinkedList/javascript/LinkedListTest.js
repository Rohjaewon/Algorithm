const LinkedList = require('./LinkedList');

let l = new LinkedList();
l.append(1);
l.append(2);
l.prepend(3);

l.deleteTail();

l.display();