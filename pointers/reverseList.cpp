void reverse(Node* ptr) {

	if (ptr == nullptr) {
		return;
	}
	else {
		Node* nextLink = ptr->link;
		reverse(nextLink);

		if (nextLink != nullptr) {
			nextLink->link = ptr;
		}
		ptr->link = nullptr;
	}
}
