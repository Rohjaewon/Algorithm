const LinkedListNode = require('./LinkedListNode');

module.exports = class LinkedList {
    constructor() {
        /**@var LinkedListNode */
        this.head = null;

        /**@var LinkedListNode */
        this.tail = null;
    }

    /**
     * 
     */
    display() {
        let currentNode = this.head;
        console.log("LinkedList : ");
        while (currentNode != null) {
            console.log(currentNode.value);
            currentNode = currentNode.next;
        }
    }

    /**
     * @param {*} value
     * @return {LinkedList}
     */
    prepend(value) {
        const newNode = new LinkedListNode(value, this.head);
        this.head = newNode;

        if (!this.tail) {
            this.tail = newNode;
        }
        return this;
    }

    /**
     * @param {*} value
     * @return {LinkedList}
     */
    append(value) {
        const newNode = new LinkedListNode(value);

        if (!this.head) {
            this.head = newNode;
            this.tail = newNode;

            return this;
        }

        this.tail.next = newNode;
        this.tail = newNode;

        return this;
    }

    /**
     * @param {*} value
     * @return {LinkedListNode}
     */
    delete(value) {
        if (!this.head) {
            return null;
        }
        let deletedNode = null;
        while (this.head && (this.head.value === value)) {
            deletedNode = this.head;
            this.head = this.head.next;
        }

        let currentNode = this.head;
        if (currentNode !== null) {
            while (currentNode.next) {
                if (currentNode.next.value === value) {
                    deletedNode = currentNode.next;
                    currentNode.next = currentNode.next.next;
                } else {
                    currentNode = currentNode.next;
                }
            }
        }
        if (this.tail.value === value) {
            this.tail = currentNode;
        }
        return deletedNode;
    }

    /**
     * @param {Object} findParams
     * @param {*} findParams.value
     * @param {function} findParams.callback
     * @return {LinkedListNode}
     */
    find({value = undefined, callback = undefined}) {
        if (!this.head) {
            return null;
        }

        let currentNode = this.head;

        while (currentNode) {
            if (callback && callback(currentNode.value)) {
                return currentNode;
            }

            if (value !== undefined && (currentNode.value === value)) {
                return currentNode;
            }
            currentNode = currentNode.next;
        }
        return null;
    }

    /**
     * @return {LinkedListNode}
     */
    deleteTail() {
        const deletedTail = this.tail;

        if (this.head === this.tail) {
            this.head = null;
            this.tail = null;

            return deletedTail;
        }

        let currentNode = this.head;
        while (currentNode.next) {
            if (!currentNode.next.next) {
                currentNode.next = null;
            } else {
                currentNode = currentNode.next;
            }
        }
        this.tail = currentNode;
        return deletedTail;
    }

    /**
     * @return {LinkedListNode}
     */
    deleteHead() {
        if (!this.head) {
            return null;
        }

        const deletedHead = this.head;

        if (this.head.next) {
            this.head = this.head.next;
        } else {
            this.head = null;
            this.tail = null;
        }
        return deletedHead;
    }
}