// Function to create a tree node
function createNode(value) {
    return {
        value: value,
        children: []
    };
}

// Function to add a child node to a parent node
function addChild(parentNode, childNode) {
    parentNode.children.push(childNode);
}

// Function to print the tree
function printTree(node, indent = 0) {
    console.log(' '.repeat(indent) + node.value);
    node.children.forEach(child => printTree(child, indent + 2));
}

// Example usage:

// Create the root node
const root = createNode('Root');

// Create child nodes
const child1 = createNode('Child 1');
const child2 = createNode('Child 2');

// Add children to the root node
addChild(root, child1);
addChild(root, child2);

// Create grandchildren
const grandchild1 = createNode('Grandchild 1');
const grandchild2 = createNode('Grandchild 2');
const grandchild4 = createNode('Grandchild 2');
const grandchild5 = createNode('Grandchild 2');

// Add grandchildren to one of the child nodes
addChild(child1, grandchild1);
addChild(child1, grandchild2);
addChild(child1, grandchild4);
addChild(child1, grandchild5);

// Print the tree structure
printTree(root);
